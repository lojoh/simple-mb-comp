/*
  ==============================================================================

    GlobalControls.cpp
    Created: 1 Sep 2022 1:37:03pm
    Author:  ludjoh01

  ==============================================================================
*/

#include "GlobalControls.h"
#include "Params.h"
#include "Utilities.h"

GlobalControls::GlobalControls(juce::AudioProcessorValueTreeState& apvts)
{
    using namespace Params;
    const auto& params = GetParams();

    auto getParamHelper = [&params, &apvts](const auto& name) -> auto&
    {
        return getParam(apvts, params, name);
    };

    auto& gainInParam = getParamHelper(Names::Gain_In);
    auto& lowMidParam = getParamHelper(Names::Low_Mid_Crossover_Freq);
    auto& midHighParam = getParamHelper(Names::Mid_High_Crossover_Freq);
    auto& gainOutParam = getParamHelper(Names::Gain_Out);

    inGainSlider = std::make_unique<RSWL>(&gainInParam,
        "dB",
        "Input Gain");
    lowMidXoverSlider = std::make_unique<RSWL>(&lowMidParam,
        "Hz",
        "Low-Mid X-Over");
    midHighXoverSlider = std::make_unique<RSWL>(&midHighParam,
        "Hz",
        "Mid-High X-Over");
    outGainSlider = std::make_unique<RSWL>(&gainOutParam,
        "dB",
        "Output Gain");

    auto makeAttachmentHelper = [&params, &apvts](auto& attachment,
        const auto& name,
        auto& slider)
    {
        makeAttachment(attachment, apvts, params, name, slider);
    };

    makeAttachmentHelper(inGainSliderAttachment,
        Names::Gain_In,
        *inGainSlider);
    makeAttachmentHelper(lowMidXoverSliderAttachment,
        Names::Low_Mid_Crossover_Freq,
        *lowMidXoverSlider);
    makeAttachmentHelper(midHighXoverSliderAttachment,
        Names::Mid_High_Crossover_Freq,
        *midHighXoverSlider);
    makeAttachmentHelper(outGainSliderAttachment,
        Names::Gain_Out,
        *outGainSlider);

    addLabelPairs(inGainSlider->labels,
        gainInParam,
        "dB");
    addLabelPairs(lowMidXoverSlider->labels,
        lowMidParam,
        "Hz");
    addLabelPairs(midHighXoverSlider->labels,
        midHighParam,
        "Hz");
    addLabelPairs(outGainSlider->labels,
        gainOutParam,
        "dB");

    addAndMakeVisible(*inGainSlider);
    addAndMakeVisible(*lowMidXoverSlider);
    addAndMakeVisible(*midHighXoverSlider);
    addAndMakeVisible(*outGainSlider);
}

void GlobalControls::paint(juce::Graphics& g)
{
    auto bounds = getLocalBounds();
    drawModuleBackground(g, bounds);
}

void GlobalControls::resized()
{
    auto bounds = getLocalBounds().reduced(5);
    using namespace juce;

    FlexBox flexbox;
    flexbox.flexDirection = FlexBox::Direction::row;
    flexbox.flexWrap = FlexBox::Wrap::noWrap;

    auto spacer = FlexItem().withWidth(4);
    auto endCap = FlexItem().withWidth(6);

    flexbox.items.add(endCap);
    flexbox.items.add(FlexItem(*inGainSlider).withFlex(1.f));
    flexbox.items.add(spacer);
    flexbox.items.add(FlexItem(*lowMidXoverSlider).withFlex(1.f));
    flexbox.items.add(spacer);
    flexbox.items.add(FlexItem(*midHighXoverSlider).withFlex(1.f));
    flexbox.items.add(spacer);
    flexbox.items.add(FlexItem(*outGainSlider).withFlex(1.f));
    flexbox.items.add(endCap);

    flexbox.performLayout(bounds);

}
