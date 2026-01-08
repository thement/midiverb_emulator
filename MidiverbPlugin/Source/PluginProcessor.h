#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <array>
#include <atomic>
#include <cstdint>
#include <cmath>

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

// Output interpolation buffer (cubic Hermite interpolation)
// Used for upsampling: effect rate -> host rate
struct OutputInterpBuffer {
    static constexpr int SIZE = 4;
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

    // Cubic Hermite interpolation, frac in [0, 1)
    // Interpolates between 3rd and 2nd most recent samples (1-sample latency)
    // This ensures we have samples on both sides for proper cubic interp
    double interpolate(double frac) const {
        int i0 = writePos;                       // oldest (for slope at start)
        int i1 = (writePos + 1) % SIZE;          // 3rd most recent (interp start)
        int i2 = (writePos + 2) % SIZE;          // 2nd most recent (interp end)
        int i3 = (writePos + 3) % SIZE;          // most recent (for slope at end)

        double y0 = data[i0], y1 = data[i1], y2 = data[i2], y3 = data[i3];

        // Cubic Hermite spline: at frac=0 returns y1, at frac=1 returns y2
        double c0 = y1;
        double c1 = 0.5 * (y2 - y0);
        double c2 = y0 - 2.5 * y1 + 2.0 * y2 - 0.5 * y3;
        double c3 = 0.5 * (y3 - y0) + 1.5 * (y1 - y2);

        return ((c3 * frac + c2) * frac + c1) * frac + c0;
    }
};

// Input interpolation buffer (cubic Hermite interpolation)
// Used for downsampling: host rate -> effect rate
// Extrapolates the "future" sample for slope estimation
struct InputInterpBuffer {
    static constexpr int SIZE = 4;
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

    // Cubic Hermite interpolation between 2nd newest and newest samples
    // frac=0 gives 2nd newest, frac=1 gives newest
    double interpolate(double frac) const {
        int i0 = (writePos + 1) % SIZE;  // 3rd newest (for slope at start)
        int i1 = (writePos + 2) % SIZE;  // 2nd newest (interp start)
        int i2 = (writePos + 3) % SIZE;  // newest (interp end)

        double y0 = data[i0], y1 = data[i1], y2 = data[i2];
        // Extrapolate y3 for slope at y2 (linear extrapolation)
        double y3 = 2.0 * y2 - y1;

        // Cubic Hermite spline
        double c0 = y1;
        double c1 = 0.5 * (y2 - y0);
        double c2 = y0 - 2.5 * y1 + 2.0 * y2 - 0.5 * y3;
        double c3 = 0.5 * (y3 - y0) + 1.5 * (y1 - y2);

        return ((c3 * frac + c2) * frac + c1) * frac + c0;
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

    // Effect state (int16_t version for standard mode)
    std::array<int16_t, 0x4000> DRAM;
    // Effect state (float version for hi-quality mode)
    std::array<float, 0x4000> DRAMFloat;
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

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiverbAudioProcessor)
};
