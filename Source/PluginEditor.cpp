/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicSamplerAudioProcessorEditor::BasicSamplerAudioProcessorEditor (BasicSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    mLoadButton.onClick = [&]() { audioProcessor.loadFile(); };
    addAndMakeVisible(mLoadButton);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
}

BasicSamplerAudioProcessorEditor::~BasicSamplerAudioProcessorEditor()
{
}

//==============================================================================
void BasicSamplerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    
    if(audioProcessor.getNumSamplerSounds() > 0)
    {
        g.fillAll(juce::Colours::red);
        g.drawFittedText ("Sound Loaded!", getLocalBounds(), juce::Justification::centred, 1);
    } else {
        g.drawFittedText ("Load A Sound...", getLocalBounds(), juce::Justification::centred, 1);
    }
}

void BasicSamplerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
//    mLoadButton.setBounds(getWidth() / 2 - 50 , getHeight() / 2 - 50, 100, 100);
}

bool BasicSamplerAudioProcessorEditor::isInterestedInFileDrag(const juce::StringArray& files)
{
    for(auto file : files)
    {
        if (file.contains("wav") || file.contains("aif"))
        {
            return true;
        }
    }
    
    return false;
}

void BasicSamplerAudioProcessorEditor::filesDropped(const juce::StringArray& files, int x, int y)
{
    for(auto file : files)
    {
        if(isInterestedInFileDrag(file))
        {
            audioProcessor.loadFile(file);
        }
    }
    
    repaint();
}
