#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include "PluginProcessor.h"

class MidiverbAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit MidiverbAudioProcessorEditor(MidiverbAudioProcessor&);
    ~MidiverbAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    MidiverbAudioProcessor& audioProcessor;

    // Program selector
    juce::ComboBox programSelector;
    juce::Label programLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> programAttachment;

    // Dry/Wet knob
    juce::Slider dryWetSlider;
    juce::Label dryWetLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dryWetAttachment;

    // Feedback knob
    juce::Slider feedbackSlider;
    juce::Label feedbackLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiverbAudioProcessorEditor)
};
