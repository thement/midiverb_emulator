#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include "PluginProcessor.h"

class MidiverbAudioProcessorEditor : public juce::AudioProcessorEditor,
                                     private juce::Timer
{
public:
    static constexpr int defaultWidth = 500;
    static constexpr int defaultHeight = 340;

    explicit MidiverbAudioProcessorEditor(MidiverbAudioProcessor&);
    ~MidiverbAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;
    void mouseDown(const juce::MouseEvent&) override;

private:
    void timerCallback() override;
    void updateProgramSelector();
    MidiverbAudioProcessor& audioProcessor;

    // Device selector
    juce::ComboBox deviceSelector;
    juce::Label deviceLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> deviceAttachment;
    int lastDeviceIndex = -1;

    // Program selector (manually managed, not using attachment due to variable effect counts)
    juce::ComboBox programSelector;
    juce::Label programLabel;
    int lastProgramIndex = -1;  // Track last synced parameter value

    // Dry/Wet knob
    juce::Slider dryWetSlider;
    juce::Label dryWetLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dryWetAttachment;

    // Feedback knob
    juce::Slider feedbackSlider;
    juce::Label feedbackLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;

    // Input overload indicator
    bool showOverload = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiverbAudioProcessorEditor)
};
