/*
  ==============================================================================

    GlobalControls.h
    Created: 1 Sep 2022 1:37:03pm
    Author:  ludjoh01

  ==============================================================================
*/

#pragma once

#include<JuceHeader.h>
#include "RotarySliderWithLabels.h"

struct GlobalControls : juce::Component
{
    GlobalControls(juce::AudioProcessorValueTreeState& apvts);

    void paint(juce::Graphics& g) override;

    void resized() override;
private:
    using RSWL = RotarySliderWithLabels;
    std::unique_ptr<RSWL> inGainSlider, lowMidXoverSlider, midHighXoverSlider, outGainSlider;

    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<Attachment> lowMidXoverSliderAttachment,
        midHighXoverSliderAttachment,
        inGainSliderAttachment,
        outGainSliderAttachment;
};