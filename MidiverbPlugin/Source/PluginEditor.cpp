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

    // Program selector
    programLabel.setText("Program", juce::dontSendNotification);
    programLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(programLabel);
    addAndMakeVisible(programSelector);

    programAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
        audioProcessor.getAPVTS(), "program", programSelector);

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

    if (deviceIndex == lastDeviceIndex)
        return;

    lastDeviceIndex = deviceIndex;

    // Save current program
    int currentProgram = static_cast<int>(*audioProcessor.getAPVTS().getRawParameterValue("program"));

    // Detach temporarily to avoid feedback loops
    programAttachment.reset();

    programSelector.clear(juce::dontSendNotification);

    int firstProg = MidiverbAudioProcessor::getDeviceFirstProgram(deviceIndex);
    int lastProg = MidiverbAudioProcessor::getDeviceLastProgram(deviceIndex);

    for (int prog = firstProg; prog <= lastProg; ++prog) {
        juce::String name = MidiverbAudioProcessor::getEffectName(deviceIndex, prog);
        programSelector.addItem(juce::String(prog) + ": " + name, prog + 1);  // ComboBox IDs are 1-based
    }

    // Clamp current program to valid range for this device
    if (currentProgram < firstProg) currentProgram = firstProg;
    if (currentProgram > lastProg) currentProgram = lastProg;

    programSelector.setSelectedId(currentProgram + 1, juce::dontSendNotification);

    // Reattach
    programAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
        audioProcessor.getAPVTS(), "program", programSelector);
}

void MidiverbAudioProcessorEditor::timerCallback()
{
    // Check for device changes
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
