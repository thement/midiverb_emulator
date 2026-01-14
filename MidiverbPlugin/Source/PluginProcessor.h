#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <array>
#include <atomic>
#include <cstdint>
#include <cmath>

// Forward declarations for LFO types (defined in lfo.h)
struct Lfo;
struct LfoPatch;

// Biquad filter section (transposed direct form II)
struct Biquad {
    double b0 = 1, b1 = 0, b2 = 0;
    double a1 = 0, a2 = 0;
    double z1 = 0, z2 = 0;

    void reset() { z1 = z2 = 0; }

    double process(double x) {
        double y = b0 * x + z1;
        z1 = b1 * x - a1 * y + z2;
        z2 = b2 * x - a2 * y;
        return y;
    }

    // Set as Butterworth lowpass for one section of an Nth order filter
    // Q values for Butterworth: Q = 1 / (2 * cos(pi * (2*k + 1) / (2*N)))
    void setLowpass(double sampleRate, double cutoff, double Q) {
        double w0 = 2.0 * 3.1415926 * cutoff / sampleRate;
        double cosw0 = std::cos(w0);
        double sinw0 = std::sin(w0);
        double alpha = sinw0 / (2.0 * Q);

        double a0 = 1.0 + alpha;
        b0 = ((1.0 - cosw0) / 2.0) / a0;
        b1 = (1.0 - cosw0) / a0;
        b2 = ((1.0 - cosw0) / 2.0) / a0;
        a1 = (-2.0 * cosw0) / a0;
        a2 = (1.0 - alpha) / a0;
    }
};

// 8th order Butterworth lowpass (4 cascaded biquads)
struct LowpassFilter8 {
    std::array<Biquad, 4> sections;

    void reset() {
        for (auto& s : sections) s.reset();
    }

    void setCutoff(double sampleRate, double cutoff) {
        // Q values for 8th order Butterworth
        // Q_k = 1 / (2 * cos(pi * (2*k + 1) / 16)) for k = 0,1,2,3
        static const double Qs[4] = {
            0.5097956518,  // k=0
            0.6013448869,  // k=1
            0.8999197654,  // k=2
            2.5629154478   // k=3
        };
        for (int i = 0; i < 4; i++) {
            sections[i].setLowpass(sampleRate, cutoff, Qs[i]);
        }
    }

    double process(double x) {
        for (auto& s : sections) {
            x = s.process(x);
        }
        return x;
    }
};

// Output interpolation buffer (linear interpolation)
// Used for upsampling: effect rate -> host rate
struct OutputInterpBuffer {
    static constexpr int SIZE = 2;
    std::array<double, SIZE> data = {};
    int writePos = 0;

    void reset() {
        data.fill(0);
        writePos = 0;
    }

    void push(double x) {
        data[writePos] = x;
        writePos = (writePos + 1) % SIZE;
    }

    // Linear interpolation between oldest and newest
    // frac=0 gives oldest, frac=1 gives newest
    double interpolate(double frac) const {
        int i0 = writePos;              // oldest
        int i1 = (writePos + 1) % SIZE; // newest
        return data[i0] + frac * (data[i1] - data[i0]);
    }
};

// Input interpolation buffer (linear interpolation)
// Used for downsampling: host rate -> effect rate
struct InputInterpBuffer {
    static constexpr int SIZE = 2;
    std::array<double, SIZE> data = {};
    int writePos = 0;

    void reset() {
        data.fill(0);
        writePos = 0;
    }

    void push(double x) {
        data[writePos] = x;
        writePos = (writePos + 1) % SIZE;
    }

    // Linear interpolation between 2nd newest and newest
    // frac=0 gives 2nd newest, frac=1 gives newest
    double interpolate(double frac) const {
        int i0 = writePos;              // 2nd newest (older)
        int i1 = (writePos + 1) % SIZE; // newest
        return data[i0] + frac * (data[i1] - data[i0]);
    }
};

class MidiverbAudioProcessor : public juce::AudioProcessor
{
public:
    MidiverbAudioProcessor();
    ~MidiverbAudioProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getAPVTS() { return apvts; }

    static constexpr int NUM_DEVICES = 3;
    static constexpr int MAX_PROGRAMS = 100;  // MIDIVerb 2 has 100 programs (0-99)
    static constexpr double EFFECT_SAMPLE_RATE = 24000.0;
    static constexpr double FILTER_CUTOFF = 10000.0;  // Below 12kHz Nyquist

    // Device info accessors
    static const char* getDeviceName(int deviceIndex);
    static int getDeviceNumEffects(int deviceIndex);
    static int getDeviceDisplayOffset(int deviceIndex);
    static const char* getEffectName(int deviceIndex, int effectIndex);

    // Input overload detection
    bool getAndClearInputOverload() { return inputOverload.exchange(false); }

private:
    juce::AudioProcessorValueTreeState apvts;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    // Effect state
    std::array<int16_t, 0x4000> DRAM;
    int memoryPointer = 0;
    double lastWetL = 0.0;
    double lastWetR = 0.0;

    // Resampling state
    double hostSampleRate = 48000.0;
    double phase = 0.0;           // Fractional position in effect sample stream
    double phaseIncrement = 1.0;  // 24000 / hostRate

    // Anti-aliasing filter (before downsampling) - mono input
    LowpassFilter8 antiAliasFilter;

    // Input interpolation buffer (for downsampling to effect rate)
    InputInterpBuffer inputBuffer;

    // Output interpolation buffers (effect outputs stereo)
    OutputInterpBuffer outputBufferL;
    OutputInterpBuffer outputBufferR;

    // Reconstruction filters (after upsampling) - stereo
    LowpassFilter8 reconstructFilterL;
    LowpassFilter8 reconstructFilterR;

    // Input overload detection
    std::atomic<bool> inputOverload{false};

    // LFO state for MIDIVerb 2 flanger/chorus effects (50-69)
    Lfo* lfo1 = nullptr;
    Lfo* lfo2 = nullptr;
    LfoPatch* currentLfoPatch = nullptr;
    uint32_t lfo1Value = 0;
    uint32_t lfo2Value = 0;
    int lfoSampleCounter = 0;
    int lastDeviceIndex = -1;
    int lastEffectIndex = -1;
    static constexpr int LFO_UPDATE_INTERVAL = 8;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiverbAudioProcessor)
};
