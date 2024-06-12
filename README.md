# Midiverb I emulator

![Panel](panel.jpg)

This is an emulator for the original MIDIVERB and MIDIFEX effect units made by Alesis.

This emulator is based on reverse engineering work done by [Paul Schreiber of SynthTech](https://www.youtube.com/@MOTMguy). If you are into synthesizers and electronics, it's a must watch!

* https://www.youtube.com/watch?v=z4cIt1VPAjU
* https://www.youtube.com/watch?v=JNPpU08YZjk
* https://www.youtube.com/watch?v=5DYbirWuBaU

So far this is only a standalone C program that processes .WAV files, but in future it will be adapted into plugins/VCVRack module/Raspberry Pi Pico device.

## Emulation

So far it's emulated:

- the core DSP engine
- output saturation

What's missing:

- input pre-emphasis and filtering

## Build

Requires libsndfile to build.

```
apt-get install libsndfile-dev
```

Then just make.

## Usage

Inputs and outputs are stereo WAV files, 22 KHz, 16-bit, signed integer.

The output is 100% wet.

```
$ sox i_feel_so_liberated.wav -t wav -e signed-integer -b 16 -r 22050 input.wav
$ ./midiverb midiverb.rom 21 input.wav output.wav
channels=2, sample_rate=22050, num=198636
```

The programs are indexed from 1 in the same way as they are on the original unit.


### List of programs

TODO: Create a table with list of programs


## Supported ROMs

The effect ROM is not distributed with this program and you have to obtain it yourself. If you own a MIDIVERB/MIDIFEX unit and don't want to dump the EEPROM yourself, you might look for a synthesizer rom archive.

This program was tested with the following roms

| MD5SUM | ROM name |
|---|---|
| 11a460c8e64d3325411bba0c11a2ae49  | midiverb.rom |
| f06003307a93ec09c637146ecaa17948  | midifex.rom |




