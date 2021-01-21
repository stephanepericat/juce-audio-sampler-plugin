/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicSamplerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    BasicSamplerAudioProcessorEditor (BasicSamplerAudioProcessor&);
    ~BasicSamplerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::TextButton mLoadButton { "Load" };
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicSamplerAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicSamplerAudioProcessorEditor)
};
