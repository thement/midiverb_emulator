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

    setSize(defaultWidth, defaultHeight);
    setResizable(true, true);
    setResizeLimits(400, 272, 1000, 680);
    getConstrainer()->setFixedAspectRatio(static_cast<double>(defaultWidth) / defaultHeight);

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
    const float scale = static_cast<float>(getHeight()) / defaultHeight;

    g.fillAll(juce::Colours::darkgrey);

    g.setColour(juce::Colours::white);
    g.setFont(20.0f * scale);
    const int titleHeight = static_cast<int>(40 * scale);
    g.drawFittedText("Midiverb Emulator", getLocalBounds().removeFromTop(titleHeight),
                     juce::Justification::centred, 1);

    // Input overload indicator (positioned relative to top-right)
    const float indicatorSize = 15.0f * scale;
    const float indicatorMargin = 10.0f * scale;
    auto indicatorBounds = juce::Rectangle<float>(
        getWidth() - indicatorSize - indicatorMargin,
        indicatorMargin,
        indicatorSize,
        indicatorSize);
    g.setColour(showOverload ? juce::Colours::red : juce::Colours::darkred);
    g.fillEllipse(indicatorBounds);
}

void MidiverbAudioProcessorEditor::resized()
{
    const float scale = static_cast<float>(getHeight()) / defaultHeight;
    auto area = getLocalBounds();

    // Scale fonts for labels
    const float labelFontSize = 14.0f * scale;
    juce::Font labelFont = juce::Font(juce::FontOptions().withHeight(labelFontSize));

    deviceLabel.setFont(labelFont);
    programLabel.setFont(labelFont);
    dryWetLabel.setFont(labelFont);
    feedbackLabel.setFont(labelFont);

    // Title area: ~15% of height
    const int titleHeight = static_cast<int>(50 * scale);
    area.removeFromTop(titleHeight);

    // Selector rows: ~15% each
    const int selectorRowHeight = static_cast<int>(50 * scale);
    const int labelHeight = static_cast<int>(20 * scale);
    const int hPadding = static_cast<int>(20 * scale);
    const int vPadding = static_cast<int>(5 * scale);

    // Device selector
    auto deviceArea = area.removeFromTop(selectorRowHeight);
    deviceLabel.setBounds(deviceArea.removeFromTop(labelHeight));
    deviceSelector.setBounds(deviceArea.reduced(hPadding, vPadding));

    // Program selector
    auto selectorArea = area.removeFromTop(selectorRowHeight);
    programLabel.setBounds(selectorArea.removeFromTop(labelHeight));
    programSelector.setBounds(selectorArea.reduced(hPadding, vPadding));

    // Knob area: remaining space
    const int knobPaddingH = static_cast<int>(20 * scale);
    const int knobPaddingV = static_cast<int>(10 * scale);
    auto knobArea = area.reduced(knobPaddingH, knobPaddingV);
    auto knobWidth = knobArea.getWidth() / 2;

    // Scale text box size proportionally
    const int textBoxWidth = static_cast<int>(60 * scale);
    const int textBoxHeight = static_cast<int>(20 * scale);
    dryWetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, textBoxWidth, textBoxHeight);
    feedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, textBoxWidth, textBoxHeight);

    // Dry/Wet knob
    auto dryWetArea = knobArea.removeFromLeft(knobWidth);
    dryWetLabel.setBounds(dryWetArea.removeFromTop(labelHeight));
    dryWetSlider.setBounds(dryWetArea.reduced(static_cast<int>(10 * scale), 0));

    // Feedback knob
    auto feedbackArea = knobArea;
    feedbackLabel.setBounds(feedbackArea.removeFromTop(labelHeight));
    feedbackSlider.setBounds(feedbackArea.reduced(static_cast<int>(10 * scale), 0));
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
