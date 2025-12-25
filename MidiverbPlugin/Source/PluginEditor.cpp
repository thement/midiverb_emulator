#include "PluginProcessor.h"
#include "PluginEditor.h"

MidiverbAudioProcessorEditor::MidiverbAudioProcessorEditor(MidiverbAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Program selector
    programLabel.setText("Program", juce::dontSendNotification);
    programLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(programLabel);

    for (int i = 1; i <= MidiverbAudioProcessor::NUM_EFFECTS; ++i)
        programSelector.addItem(juce::String(i) + ": " + MidiverbAudioProcessor::getEffectName(i - 1), i);

    programSelector.setSelectedId(1);
    addAndMakeVisible(programSelector);

    // ComboBox attachment needs special handling for AudioParameterInt
    programAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
        audioProcessor.getAPVTS(), "program", programSelector);

    // Dry/Wet slider
    dryWetLabel.setText("Dry/Wet", juce::dontSendNotification);
    dryWetLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(dryWetLabel);

    dryWetSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    dryWetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
    addAndMakeVisible(dryWetSlider);

    dryWetAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getAPVTS(), "dryWet", dryWetSlider);

    // Feedback slider
    feedbackLabel.setText("Feedback", juce::dontSendNotification);
    feedbackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(feedbackLabel);

    feedbackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    feedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
    addAndMakeVisible(feedbackSlider);

    feedbackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getAPVTS(), "feedback", feedbackSlider);

    setSize(500, 300);
}

MidiverbAudioProcessorEditor::~MidiverbAudioProcessorEditor()
{
}

void MidiverbAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

    g.setColour(juce::Colours::white);
    g.setFont(20.0f);
    g.drawFittedText("Midiverb Emulator", getLocalBounds().removeFromTop(40),
                     juce::Justification::centred, 1);
}

void MidiverbAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    area.removeFromTop(50); // Space for title

    auto selectorArea = area.removeFromTop(60);
    programLabel.setBounds(selectorArea.removeFromTop(20));
    programSelector.setBounds(selectorArea.reduced(20, 5));

    auto knobArea = area.reduced(20, 10);
    auto knobWidth = knobArea.getWidth() / 2;

    // Dry/Wet knob
    auto dryWetArea = knobArea.removeFromLeft(knobWidth);
    dryWetLabel.setBounds(dryWetArea.removeFromTop(20));
    dryWetSlider.setBounds(dryWetArea.reduced(10, 0));

    // Feedback knob
    auto feedbackArea = knobArea;
    feedbackLabel.setBounds(feedbackArea.removeFromTop(20));
    feedbackSlider.setBounds(feedbackArea.reduced(10, 0));
}
