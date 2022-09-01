/*
  ==============================================================================

    CustomButtons.h
    Created: 1 Sep 2022 1:14:04pm
    Author:  ludjoh01

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

struct PowerButton : juce::ToggleButton { };

struct AnalyzerButton : juce::ToggleButton
{
    void resized() override;

    juce::Path randomPath;
};