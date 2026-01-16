#include "PluginProcessor.h"
#include "PluginEditor.h"

MidiverbAudioProcessorEditor::MidiverbAudioProcessorEditor(MidiverbAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Device selector
    deviceLabel.setText("Device", juce::dontSendNotification);
    deviceLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(deviceLabel);

    for (int i = 0; i < MidiverbAudioProcessor::NUM_DEVICES; ++i)
        deviceSelector.addItem(MidiverbAudioProcessor::getDeviceName(i), i + 1);

    addAndMakeVisible(deviceSelector);

    deviceAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
        audioProcessor.getAPVTS(), "device", deviceSelector);

    // Program selector (manually managed due to variable effect counts per device)
    programLabel.setText("Program", juce::dontSendNotification);
    programLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(programLabel);
    addAndMakeVisible(programSelector);

    // Manual onChange handler - ComboBox ID equals effect index + 1
    programSelector.onChange = [this]() {
        int effectIndex = programSelector.getSelectedId() - 1;
        if (effectIndex >= 0) {
            auto* param = audioProcessor.getAPVTS().getParameter("program");
            param->setValueNotifyingHost(param->convertTo0to1(static_cast<float>(effectIndex)));
        }
    };

    // Initialize program list for current device
    updateProgramSelector();

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

    setSize(500, 340);

    startTimerHz(30);
}

MidiverbAudioProcessorEditor::~MidiverbAudioProcessorEditor()
{
    stopTimer();
}

void MidiverbAudioProcessorEditor::updateProgramSelector()
{
    int deviceIndex = static_cast<int>(*audioProcessor.getAPVTS().getRawParameterValue("device"));
    int currentIndex = static_cast<int>(*audioProcessor.getAPVTS().getRawParameterValue("program"));

    // Rebuild combo box items only when device changes
    if (deviceIndex != lastDeviceIndex)
    {
        lastDeviceIndex = deviceIndex;
        lastProgramIndex = -1;  // Force sync after device change
        programSelector.clear(juce::dontSendNotification);

        int numEffects = MidiverbAudioProcessor::getDeviceNumEffects(deviceIndex);
        int displayOffset = MidiverbAudioProcessor::getDeviceDisplayOffset(deviceIndex);

        // ComboBox ID = effect index + 1 (direct mapping, no normalization)
        for (int i = 0; i < numEffects; ++i) {
            int displayNum = i + displayOffset;
            juce::String name = MidiverbAudioProcessor::getEffectName(deviceIndex, i);
            programSelector.addItem(juce::String(displayNum) + ": " + name, i + 1);
        }
    }

    // Clamp to valid range
    int numEffects = MidiverbAudioProcessor::getDeviceNumEffects(deviceIndex);
    if (currentIndex < 0) currentIndex = 0;
    if (currentIndex >= numEffects) currentIndex = numEffects - 1;

    // Only sync combo box when parameter value has changed (not on every tick)
    // This avoids fighting with user interaction
    if (currentIndex != lastProgramIndex)
    {
        lastProgramIndex = currentIndex;
        programSelector.setSelectedId(currentIndex + 1, juce::dontSendNotification);
    }

    // Update parameter only if it was clamped
    int paramValue = static_cast<int>(*audioProcessor.getAPVTS().getRawParameterValue("program"));
    if (currentIndex != paramValue) {
        auto* param = audioProcessor.getAPVTS().getParameter("program");
        param->setValueNotifyingHost(param->convertTo0to1(static_cast<float>(currentIndex)));
    }
}

void MidiverbAudioProcessorEditor::timerCallback()
{
    // Check for device changes (this also syncs the program selector)
    updateProgramSelector();

    if (audioProcessor.getAndClearInputOverload())
    {
        showOverload = true;
        repaint();
    }
    else if (showOverload)
    {
        showOverload = false;
        repaint();
    }
}

void MidiverbAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

    g.setColour(juce::Colours::white);
    g.setFont(20.0f);
    g.drawFittedText("Midiverb Emulator", getLocalBounds().removeFromTop(40),
                     juce::Justification::centred, 1);

    // Input overload indicator
    auto indicatorBounds = juce::Rectangle<float>(getWidth() - 25.0f, 10.0f, 15.0f, 15.0f);
    g.setColour(showOverload ? juce::Colours::red : juce::Colours::darkred);
    g.fillEllipse(indicatorBounds);
}

void MidiverbAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    area.removeFromTop(50); // Space for title

    // Device selector
    auto deviceArea = area.removeFromTop(50);
    deviceLabel.setBounds(deviceArea.removeFromTop(20));
    deviceSelector.setBounds(deviceArea.reduced(20, 5));

    // Program selector
    auto selectorArea = area.removeFromTop(50);
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

void MidiverbAudioProcessorEditor::mouseDown(const juce::MouseEvent& e)
{
    if (e.mods.isPopupMenu())
    {
        juce::PopupMenu menu;
        menu.addItem(1, juce::String("Build: ") + __DATE__ + " " + __TIME__, false);
        menu.showMenuAsync(juce::PopupMenu::Options());
    }
}
