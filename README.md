# ADSR
ADSR Envelope Generator for Modular Synth
---
##Introduction
###What's an ADSR Envelope Generator?
**ADSR** is short for _Attack-Decay-Sustain-Release_, and these 4 terms describe how a lot of sounds evolve over time. An **Envelope Generator** is a type of signal generator, but it can generate one-shot signals as well as periodic signals. Envelope generators (EGs) are ubiquitous in synthesizers. They can be used to modulate loads of parameters; here are just a few of the most common uses of an EG:
* _modulate volume_: One of the things that makes a trumpet sound different from a guitar is how the volume of a note evolves over time. A trumpet note can maintain a steady volume for many seconds, but the volume of a note on a piano decays over time.
* _modulate filter cutoff frequency_: Lots of wind instruments sound brighter when more air flows through them, and using an EG to modulate the cutoff frequency allows synthesizers to mimic this aspect of real instruments.
* _modulate carrier/modulator amplitude_: FM synthesizes are an alternative to the more common subtractive synthesizers, and in FM synthesis, EGs are used to modulate the volume of carrier and modulator waveforms (usually just sine waves) to achieve very complex tones often unrealizable with subtractive synthesis.

To sum things up, without EGs, synthesizers would be _very_ boring since they would only be able to play static sounds.

Hopefully now you're convinced that envelope generators are a worthwhile enterprise and you're wondering what _attack_, _decay_, _sustain_, and _release_ actually mean. Here's a picture that will complement the descrition below:

![adsr_explanation](/images/adsr_explanation.png)