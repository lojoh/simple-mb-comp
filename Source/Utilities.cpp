/*
  ==============================================================================

    Utilities.cpp
    Created: 1 Sep 2022 1:21:17pm
    Author:  ludjoh01

  ==============================================================================
*/

#include "Utilities.h"

juce::String getValString(const juce::RangedAudioParameter& param,
    bool getLow,
    juce::String suffix)
{
    juce::String str;

    auto val = getLow ? param.getNormalisableRange().start :
        param.getNormalisableRange().end;

    bool useK = truncateKiloValue(val);
    str << val;

    if (useK)
        str << "k";

    str << suffix;

    return str;
};

void drawModuleBackground(juce::Graphics& g,
    juce::Rectangle<int> bounds)
{
    using namespace juce;
    g.setColour(Colours::blueviolet);
    g.fillAll();

    auto localbounds = bounds;

    bounds.reduce(3, 3);
    g.setColour(Colours::black);
    g.fillRoundedRectangle(bounds.toFloat(), 3);

    g.drawRect(localbounds);
}
