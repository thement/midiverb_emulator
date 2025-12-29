#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <cmath>

#include "Effects.h"

// Effect names from all.txt
static const char* effectNames[128] = {
    ".2 Sec SMALL BRIGHT",
    ".2 Sec SMALL WARM",
    ".2 Sec MEDIUM BRIGHT",
    ".3 Sec SMALL BRIGHT",
    ".3 Sec SMALL WARM",
    ".4 Sec MEDIUM BRIGHT",
    ".4 Sec MEDIUM WARM",
    ".6 Sec SMALL BRIGHT",
    ".6 Sec MEDIUM WARM",
    ".6 Sec MEDIUM DARK",
    ".8 Sec SMALL BRIGHT",
    ".8 Sec LARGE WARM",
    "1.0 Sec SMALL WARM",
    "1.0 Sec MEDIUM WARM",
    "1.0 Sec LARGE BRIGHT",
    "1.2 Sec MEDIUM WARM",
    "1.2 Sec SMALL WARM",
    "1.2 Sec SMALL BRIGHT",
    "1.4 Sec LARGE WARM",
    "1.4 Sec LARGE DARK",
    "1.4 Sec MEDIUM WARM",
    "1.6 Sec SMALL DARK",
    "1.6 Sec LARGE BRIGHT",
    "1.6 Sec MEDIUM BRIGHT",
    "1.8 Sec LARGE DARK",
    "1.8 Sec LARGE BRIGHT",
    "1.8 Sec MEDIUM WARM",
    "2.0 Sec LARGE BRIGHT",
    "2.0 Sec MEDIUM WARM",
    "2.0 Sec LARGE WARM",
    "2.5 Sec MEDIUM WARM",
    "2.5 Sec LARGE BRIGHT",
    "2.5 Sec MEDIUM DARK",
    "2.8 Sec SMALL BRIGHT",
    "2.8 Sec MEDIUM BRIGHT",
    "3.0 Sec LARGE BRIGHT",
    "3.0 Sec LARGE WARM",
    "3.0 Sec MEDIUM DARK",
    "3.5 Sec LARGE BRIGHT",
    "3.5 Sec MEDIUM WARM",
    "4.0 Sec LARGE DARK",
    "4.0 Sec MEDIUM BRIGHT",
    "5 Sec LARGE WARM",
    "8 Sec LARGE BRIGHT",
    "8 Sec LARGE WARM",
    "10 Sec LARGE BRIGHT",
    "10 Sec LARGE WARM",
    "16 Sec LARGE DARK",
    "18 Sec EX. LARGE BRIGHT",
    "20 Sec EX. LARGE DARK",
    "Gated 100 MS",
    "Gated 150 MS",
    "Gated 200 MS",
    "Gated 250 MS",
    "Gated 300 MS",
    "Gated 350 MS",
    "Gated 400 MS",
    "Gated 500 MS",
    "Gated 600 MS",
    "REVERSE - 300 MS",
    "REVERSE - 400 MS",
    "REVERSE - 500 MS",
    "REVERSE - 600 MS",
    "DEFEAT",
    "ECHO LONG FLAT AMBI",
    "ECHO LONG FLAT THICK",
    "ECHO LONG HPF",
    "ECHO LONG HPF WIDE",
    "ECHO LONG BPF AMBI",
    "ECHO LONG LPF WIDE",
    "ECHO MED FLAT AMBI",
    "ECHO MED FLAT WIDE",
    "ECHO MED HPF AMBI",
    "ECHO MED BPF AMBI",
    "ECHO MED LPF AMBI",
    "ECHO MED LPF WIDE",
    "ECHO MED FLAT THICK",
    "ECHO SHORT FLAT",
    "ECHO SHORT LPF AMBI",
    "ECHO SHORT HPF AMBI",
    "ECHO SHORT BPF AMBI",
    "ECHO SHORT FLAT",
    "ECHO SHORT FLAT WIDE",
    "ECHO XSHORT FLAT",
    "ECHO XSHORT BPF WIDE",
    "2TAP MED FLAT AMBI",
    "2TAP MED HPF AMBI",
    "2TAP MED BPF AMBI",
    "2TAP MED FLAT THICK",
    "2TAP SHORT FLAT WIDE",
    "2TAP SHORT HPF PAN",
    "2TAP SHORT BPF AMBI",
    "2TAP SHORT LPF AMBI",
    "2TAP XSHORT FLAT WIDE",
    "3TAP MED FLAT PAN",
    "3TAP SHORT FLAT PAN",
    "3TAP SHORT LPF AMBI",
    "3TAP SHORT BPF AMBI",
    "3TAP SHORT HPF AMBI",
    "3TAP XSHORT FLAT AMBI",
    "REGEN MED FLAT",
    "REGEN MED HPF AMBI",
    "REGEN MED BPF AMBI",
    "REGEN MED LPF AMBI",
    "REGEN SHORT FLAT",
    "REGEN XSHORT FLAT",
    "SLAP1",
    "SLAP2",
    "SLAP3",
    "SLAP4",
    "SLAP5",
    "REVERB SHORT GATE",
    "REVERB MEDIUM WARM",
    "REVERB MEDIUM BLOOM",
    "REVERB MEDIUM PAN",
    "REVERB LONG HPF",
    "REVERB REVERSE",
    "REVERB REVERSE REGEN",
    "MULTITAP PAN",
    "MULTITAP REVERB",
    "MULTITAP REVERSE PAN",
    "THICKENER",
    "THICKENER DENSE",
    "STEREOGEN AMBIENT",
    "STEREOGEN THICK",
    "STEREOGEN WIDE",
    "STEREOGEN XWIDE",
    "DEFEAT"
};

const char* MidiverbAudioProcessor::getEffectName(int index)
{
    if (index >= 0 && index < NUM_EFFECTS)
        return effectNames[index];
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

    params.push_back(std::make_unique<juce::AudioParameterInt>(
        juce::ParameterID{"program", 1}, "Program", 1, NUM_EFFECTS, 1));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"dryWet", 1}, "Dry/Wet",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.5f));

    params.push_back(std::make_unique<juce::AudioParameterFloat>(
        juce::ParameterID{"feedback", 1}, "Feedback",
        juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));

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

int MidiverbAudioProcessor::getNumPrograms() { return NUM_EFFECTS; }
int MidiverbAudioProcessor::getCurrentProgram()
{
    return static_cast<int>(*apvts.getRawParameterValue("program")) - 1;
}

void MidiverbAudioProcessor::setCurrentProgram(int index)
{
    apvts.getParameter("program")->setValueNotifyingHost(
        apvts.getParameter("program")->convertTo0to1(static_cast<float>(index + 1)));
}

const juce::String MidiverbAudioProcessor::getProgramName(int index)
{
    return juce::String(index + 1) + ": " + getEffectName(index);
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
    outputBufferL.reset();
    outputBufferR.reset();

    // Reset effect state
    DRAM.fill(0);
    memoryPointer = 0;
    lastWetL = 0.0;
    lastWetR = 0.0;
    phase = 0.0;
    lastFilteredInput = 0.0;
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

    int programNo = static_cast<int>(*apvts.getRawParameterValue("program"));
    float dryWet = *apvts.getRawParameterValue("dryWet");
    float feedback = *apvts.getRawParameterValue("feedback");

    auto* leftChannel = buffer.getWritePointer(0);
    auto* rightChannel = buffer.getWritePointer(1);
    int numSamples = buffer.getNumSamples();

    float angle = dryWet * 1.5707963f;  // π/2
    float equalPowerDry = std::cos(angle);
    float equalPowerWet = std::sin(angle);

    for (int i = 0; i < numSamples; i++)
    {
        float dryL = leftChannel[i];
        float dryR = rightChannel[i];

        // Sum to mono with feedback and apply anti-aliasing filter
        double monoIn = (dryL + dryR) * 0.5 + (lastWetL + lastWetR) * 0.5 * feedback;
        double filtered = antiAliasFilter.process(monoIn);

        // Accumulate phase - process effect when we cross sample boundaries
        phase += phaseIncrement;
        while (phase >= 1.0)
        {
            phase -= 1.0;

            // Process one effect sample at 24kHz
            int16_t inputInt = static_cast<int16_t>(saturate(lastFilteredInput) * 0x1fff);
            int16_t outLeftInt, outRightInt;

            effects[programNo - 1](inputInt, &outLeftInt, &outRightInt, DRAM.data(), memoryPointer++);

            float outL = outLeftInt / static_cast<float>(0x1fff);
            float outR = outRightInt / static_cast<float>(0x1fff);

            // Push to interpolation buffers
            outputBufferL.push(outL);
            outputBufferR.push(outR);
        }
        lastFilteredInput = filtered;

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
