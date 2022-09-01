/*
  ==============================================================================

    CompressorBand.h
    Created: 1 Sep 2022 1:43:56pm
    Author:  ludjoh01

  ==============================================================================
*/

#pragma once

#include<JuceHeader.h>

struct CompressorBand
{
    juce::AudioParameterFloat* attack{ nullptr };
    juce::AudioParameterFloat* release{ nullptr };
    juce::AudioParameterFloat* threshold{ nullptr };
    juce::AudioParameterChoice* ratio{ nullptr };
    juce::AudioParameterBool* bypassed{ nullptr };
    juce::AudioParameterBool* mute{ nullptr };
    juce::AudioParameterBool* solo{ nullptr };

    void prepare(const juce::dsp::ProcessSpec& spec);

    void updateCompressorSettings();

    void process(juce::AudioBuffer<float>& buffer);
   
private:
    juce::dsp::Compressor<float> compressor;

};