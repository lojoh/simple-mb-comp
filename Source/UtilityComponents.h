/*
  ==============================================================================

    UtilityComponents.h
    Created: 1 Sep 2022 1:17:47pm
    Author:  ludjoh01

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

struct Placeholder : juce::Component
{
    Placeholder();

    void paint(juce::Graphics& g) override;
    juce::Colour customColor;
};

struct RotarySlider : juce::Slider
{
    RotarySlider();
};