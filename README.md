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

Of the 4 parameters, 3 (attack, decay, and release) are time-related, and the 4th (sustain) is a voltage.
* **Attack** sets the length of time required for the envelope to go from 0V to its maximum voltage. The attack state of the envelope begins when GATE goes from LOW to HIGH.
* **Decay** sets the length of time required for the envelope to go from its maximum voltage to a voltage set by **sustain**.
* **Release** sets the length of time required for the envelope to go from its sustain level to 0V when GATE goes from HIGH to LOW.

##First ADSR
I decided to build Jonathan Jacky's ADSR circuit because it's one of the simplest ADSRs I've seen and because many more complex ADSRs have been built around it. [This article](http://www.yusynth.net/archives/Electronics/J-Jacky-ADSR-1980.pdf) gives a good description of the circuit. The timing diagram in the article is also helpful for understanding how GATE and TRIGGER CVs operate the ADSR EG.

After I breadboarded the circuit I wanted to test it immediately, so I wrote a simple [Arduino script](/arduino/write_gate_and_trig.ino) to mimic the GATE and TRIGGER CVs required by the EG. This script also reads the ADSR EG's output so you can plot it in the Serial Plotter tool inside the Arduino IDE. This is an example of what you might see:

![arduinoIDEscreenshot](/images/arduinoIDEscreenshot.JPG)

I recorded a video to show how the envelope changes as I adjust the 4 parameters:

[![serialPlotterVideo](/images/video_links/serialPlotterVideo.JPG)](https://drive.google.com/open?id=0B5OA5X2encENR3VQa1g4UEY4YmM)

Once I was convinced the ADSR EG was working well, I plugged it in to the cutoff CV input on my synth's voltage-controlled filter (VCF) and recorded another video:

[![fakeGateAndTrigVideo](/images/video_links/fakeGateAndTrigVideo.JPG)](https://drive.google.com/open?id=0B5OA5X2encENc3hNTU1CRGI0LWs)