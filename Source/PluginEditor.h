/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/LookAndFeel.h"
#include "GUI/GlobalControls.h"
#include "GUI/CompressorBandControls.h"
#include "GUI/UtilityComponents.h"


class SimpleMBCompAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleMBCompAudioProcessorEditor (SimpleMBCompAudioProcessor&);
    ~SimpleMBCompAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    LookAndFeel lnf;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleMBCompAudioProcessor& audioProcessor;
    
    Placeholder controlBar, analyzer /*globalControls, bandControls*/;
    GlobalControls globalControls { audioProcessor.apvts };
    CompressorBandControls bandControls { audioProcessor.apvts };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleMBCompAudioProcessorEditor)
};
