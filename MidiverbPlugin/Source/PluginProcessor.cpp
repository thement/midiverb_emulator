#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cmath>

#include "Effects.h"

const char* MidiverbAudioProcessor::getDeviceName(int deviceIndex)
{
    if (deviceIndex >= 0 && deviceIndex < NUM_DEVICES)
        return devices[deviceIndex].name;
    return "Unknown";
}

int MidiverbAudioProcessor::getDeviceNumEffects(int deviceIndex)
{
    if (deviceIndex >= 0 && deviceIndex < NUM_DEVICES)
        return devices[deviceIndex].numEffects;
    return 0;
}

int MidiverbAudioProcessor::getDeviceDisplayOffset(int deviceIndex)
{
    if (deviceIndex >= 0 && deviceIndex < NUM_DEVICES)
        return devices[deviceIndex].displayOffset;
    return 0;
}

const char* MidiverbAudioProcessor::getEffectName(int deviceIndex, int effectIndex)
{
    if (deviceIndex >= 0 && deviceIndex < NUM_DEVICES) {
        const auto& dev = devices[deviceIndex];
        if (effectIndex >= 0 && effectIndex < dev.numEffects)
            return dev.effectNames[effectIndex];
    }
    return "Unknown";
}

static inline float saturate(float x)
{
    if (x <= -1.0f) return -1.0f;
    if (x >= 1.0f) return 1.0f;
    return x;
}

MidiverbAudioProcessor::MidiverbAudioProcessor()
    : AudioProcessor(BusesProperties()
                     .withInput("Input", juce::AudioChannelSet::stereo(), true)
                     .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      apvts(*this, nullptr, "Parameters", createParameterLayout())
{
    DRAM.fill(0);
}

MidiverbAudioProcessor::~MidiverbAudioProcessor()
{
}

juce::AudioProcessorValueTreeState::ParameterLayout MidiverbAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

    // Device selection (0=MIDIVerb, 1=MidiFex, 2=MIDIVerb 2)
    params.push_back(std::make_unique<juce::AudioParameterInt>(
        juce::ParameterID{"device", 1}, "Device", 0, NUM_DEVICES - 1, 2));  // Default: MIDIVerb 2

    // Program selection (0-99 range to cover all devices)
    params.push_back(std::make_unique<juce::AudioParameterInt>(
        juce::ParameterID{"program", 1}, "Program", 0, MAX_PROGRAMS - 1, 1));  // Default: program 1

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"dryWet", 1}, "Dry/Wet",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"feedback", 1}, "Feedback",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

    params.push_back(std::make_unique<juce::AudioParameterBool>(
        juce::ParameterID{"hiQuality", 1}, "Hi-Quality", false));

    return { params.begin(), params.end() };
}

const juce::String MidiverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MidiverbAudioProcessor::acceptsMidi() const { return false; }
bool MidiverbAudioProcessor::producesMidi() const { return false; }
bool MidiverbAudioProcessor::isMidiEffect() const { return false; }
double MidiverbAudioProcessor::getTailLengthSeconds() const { return 2.0; }

int MidiverbAudioProcessor::getNumPrograms() { return MAX_PROGRAMS; }
int MidiverbAudioProcessor::getCurrentProgram()
{
    return static_cast<int>(*apvts.getRawParameterValue("program"));
}

void MidiverbAudioProcessor::setCurrentProgram(int index)
{
    apvts.getParameter("program")->setValueNotifyingHost(
        apvts.getParameter("program")->convertTo0to1(static_cast<float>(index)));
}

const juce::String MidiverbAudioProcessor::getProgramName(int index)
{
    int deviceIndex = static_cast<int>(*apvts.getRawParameterValue("device"));
    int displayNum = index + getDeviceDisplayOffset(deviceIndex);
    return juce::String(displayNum) + ": " + getEffectName(deviceIndex, index);
}

void MidiverbAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

void MidiverbAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    hostSampleRate = sampleRate;
    phaseIncrement = EFFECT_SAMPLE_RATE / sampleRate;

    // Setup filters at host sample rate
    antiAliasFilter.setCutoff(sampleRate, FILTER_CUTOFF);
    antiAliasFilter.reset();

    reconstructFilterL.setCutoff(sampleRate, FILTER_CUTOFF);
    reconstructFilterL.reset();
    reconstructFilterR.setCutoff(sampleRate, FILTER_CUTOFF);
    reconstructFilterR.reset();

    // Reset interpolation buffers
    inputBuffer.reset();
    outputBufferL.reset();
    outputBufferR.reset();

    // Reset effect state
    DRAM.fill(0);
    DRAMFloat.fill(0.0f);
    memoryPointer = 0;
    lastWetL = 0.0;
    lastWetR = 0.0;
    phase = 0.0;
}

void MidiverbAudioProcessor::releaseResources()
{
}

bool MidiverbAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    if (layouts.getMainInputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    return true;
}

void MidiverbAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                           juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    int deviceIndex = static_cast<int>(*apvts.getRawParameterValue("device"));
    int effectIndex = static_cast<int>(*apvts.getRawParameterValue("program"));
    float dryWet = *apvts.getRawParameterValue("dryWet");
    float feedback = *apvts.getRawParameterValue("feedback");
    bool hiQuality = *apvts.getRawParameterValue("hiQuality") > 0.5f;

    // Clamp effect index to valid range for current device
    const auto& dev = devices[deviceIndex];
    if (effectIndex < 0) effectIndex = 0;
    if (effectIndex >= dev.numEffects) effectIndex = dev.numEffects - 1;

    // Get effect function pointers (both versions)
    auto effectFn16 = dev.effects[effectIndex];
    auto effectFnFloat = dev.effectsFloat[effectIndex];

    auto* leftChannel = buffer.getWritePointer(0);
    auto* rightChannel = buffer.getWritePointer(1);
    int numSamples = buffer.getNumSamples();

    float angle = dryWet * 1.5707963f;  // pi/2
    float equalPowerDry = std::cos(angle);
    float equalPowerWet = std::sin(angle);

    for (int i = 0; i < numSamples; i++)
    {
        float dryL = leftChannel[i];
        float dryR = rightChannel[i];

        // Sum to mono with feedback and apply anti-aliasing filter
        double monoIn = (dryL + dryR) * 0.5 + (lastWetL + lastWetR) * 0.5 * feedback;
        if (std::abs(monoIn) > 1.0)
            inputOverload.store(true, std::memory_order_relaxed);
        double filtered = antiAliasFilter.process(monoIn);

        // Push filtered sample to input buffer for interpolation
        inputBuffer.push(filtered);

        // Accumulate phase - process effect when we cross sample boundaries
        phase += phaseIncrement;
        while (phase >= 1.0)
        {
            phase -= 1.0;

            // Interpolate input at the exact fractional position where the effect sample falls
            // This eliminates beat frequency artifacts at non-integer sample rate ratios
            double inputFrac = 1.0 - phase / phaseIncrement;
            double interpolatedInput = inputBuffer.interpolate(inputFrac);

            // Process one effect sample at 24kHz
            float outL, outR;
            if (hiQuality)
            {
                // Hi-quality mode: use float arithmetic throughout
                float inputFloat = saturate(static_cast<float>(interpolatedInput));
                float outLeftFloat, outRightFloat;
                effectFnFloat(inputFloat, &outLeftFloat, &outRightFloat, DRAMFloat.data(), memoryPointer++);
                outL = outLeftFloat;
                outR = outRightFloat;
            }
            else
            {
                // Standard mode: use int16_t arithmetic (original hardware behavior)
                // Original hardware uses 13-bit samples (±4095 range, same as >> 3 from 16-bit)
                int16_t inputInt = static_cast<int16_t>(saturate(static_cast<float>(interpolatedInput)) * 0x0fff);
                int16_t outLeftInt, outRightInt;
                effectFn16(inputInt, &outLeftInt, &outRightInt, DRAM.data(), memoryPointer++);
                outL = outLeftInt / static_cast<float>(0x0fff);
                outR = outRightInt / static_cast<float>(0x0fff);
            }

            // Push to interpolation buffers
            outputBufferL.push(outL);
            outputBufferR.push(outR);
        }

        // Interpolate output at host sample rate
        double wetL = outputBufferL.interpolate(phase);
        double wetR = outputBufferR.interpolate(phase);

        // Reconstruction filter
        wetL = reconstructFilterL.process(wetL);
        wetR = reconstructFilterR.process(wetR);

        // Store for feedback
        lastWetL = wetL;
        lastWetR = wetR;

        // Dry/wet mix
        leftChannel[i] = static_cast<float>(dryL * equalPowerDry + wetL * equalPowerWet);
        rightChannel[i] = static_cast<float>(dryR * equalPowerDry + wetR * equalPowerWet);
    }
}

bool MidiverbAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* MidiverbAudioProcessor::createEditor()
{
    return new MidiverbAudioProcessorEditor(*this);
}

void MidiverbAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    auto state = apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void MidiverbAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(apvts.state.getType()))
            apvts.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MidiverbAudioProcessor();
}
