# Midiverb I emulator

![Panel](panel.jpg)

<h3>There's a <a href="https://github.com/thement/midiverb_emulator/releases">VST3 plugin</a> now. Also a <a href="http://ibawizard.net/midiverb">WEB DEMO</a>!</h3>

This is an emulator for the original MIDIVERB and MIDIFEX effect units made by Alesis.


This emulator is based on [reverse engineering work](https://github.com/emeb/MIDIVerb_RE) done by [Eric Brombaugh](https://github.com/emeb) and there's a series of videos presenting this work by [Paul Schreiber](https://www.youtube.com/@MOTMguy). If you are into synthesizers and electronics, it's a must watch!

* https://www.youtube.com/watch?v=z4cIt1VPAjU
* https://www.youtube.com/watch?v=JNPpU08YZjk
* https://www.youtube.com/watch?v=5DYbirWuBaU

<b>Update 16.7.2025:</b> All materials from the videos are now open source! It includes all the stuff - schematics of Midiverb, disassembler, compiler and emulator - check [https://github.com/emeb/MIDIVerb_RE](https://github.com/emeb/MIDIVerb_RE).


So far this is only a standalone C program that processes .WAV files, but in future it will be adapted into plugins/VCVRack module/Raspberry Pi Pico device.


## What can you find here


### Midiverb Emulator

A very naive command-line emulator of Midiverb instruction set with audio input/output. Lives in the top-level.

There's also a <a href="http://ibawizard.net/midiverb">WEB DEMO</a> of this emulator.

So far it's emulated:

- the core DSP engine
- output saturation

What's missing:

- input pre-emphasis and filtering

#### How to build it

- requires original midiverb.rom (or midifex.rom) to run
- requires libsndfile to build: `apt-get install libsndfile-dev`
- then just `make`

#### Usage

Inputs and outputs are stereo WAV files, 22 KHz, 16-bit, signed integer.

The output is 100% wet.

```
$ sox i_feel_so_liberated.wav -t wav -e signed-integer -b 16 -r 22050 input.wav
$ ./midiverb midiverb.rom 21 input.wav output.wav
channels=2, sample_rate=22050, num=198636
```

The programs are indexed from 1 in the same way as they are on the original unit.


### Midiverb decompiler

A [decompiler from Midiverb instruction set to C](disasm.py). It will also disassemble the ROMs.


It does some optimizations:

- delay-line identification
- dead code elimination
- constant folding
- calculating partial results in floating-point (that's by default, but integer calculation can be set by an option)

The output looks something like this ([full output here](all-effects.h)):

```c
void effect_22(int16_t input, int16_t *out_left, int16_t *out_right, int16_t DRAM[0x4000], int ptr) {
  int16_t Acc, tmp1, tmp2, tmp3, tmp5;
  WRITE_LINE(0, 0) = input;
  Acc = -LINE(8, 14810, 11) / 4 + -LINE(6, 13099, 796) / 4 + -LINE(4, 10902, 1001) / 4;
  tmp3 = -Acc;
  Acc = -LINE(8, 14810, 11) / 4 + -LINE(6, 13099, 445) / 4 + -LINE(4, 10902, 336) / 4;
  tmp5 = -Acc;
  Acc = LINE(0, 0, 1) / 2 + LINE(2, 8564, 1) / 2;
  WRITE_LINE(2, 8564) = Acc;
  Acc = LINE(2, 8564, 1) * 81 / 32 + LINE(14, 16381, 160) / 2;
  WRITE_LINE(14, 16381) = -Acc;
  Acc = -Acc / 2 + LINE(14, 16381, 160) + LINE(13, 16219, 215) / 2;
  WRITE_LINE(13, 16219) = -Acc;
  Acc = -Acc / 2 + LINE(13, 16219, 215) + LINE(12, 16002, 434) / 2;
  WRITE_LINE(12, 16002) = -Acc;
  Acc = -Acc / 2 + LINE(12, 16002, 434) + LINE(11, 15566, 557) / 2;
  WRITE_LINE(11, 15566) = -Acc;
  Acc = -Acc / 2 + LINE(11, 15566, 557) + LINE(10, 15007, 117) / 2;
  WRITE_LINE(10, 15007) = -Acc;
  Acc = -Acc / 2 + LINE(10, 15007, 117) + LINE(9, 14888, 76) / 2;
  WRITE_LINE(9, 14888) = -Acc;
  Acc = -Acc / 2 + LINE(9, 14888, 76);
  tmp2 = Acc;
  Acc = LINE(8, 14810, 712) * 5 / 8 + LINE(7, 14096, 995) / 2;
  WRITE_LINE(7, 14096) = -Acc;
  Acc = -Acc / 2 + LINE(7, 14096, 995);
  WRITE_LINE(6, 13099) = Acc;
  Acc = LINE(6, 13099, 1005) * 3 / 4 + LINE(5, 12092, 1188) / 2;
  WRITE_LINE(5, 12092) = -Acc;
  Acc = -Acc / 2 + LINE(5, 12092, 1188);
  WRITE_LINE(4, 10902) = Acc;
  Acc = LINE(4, 10902, 1028) * 3 / 4 + LINE(3, 9872, 1306) / 2;
  WRITE_LINE(3, 9872) = -Acc;
  Acc = -Acc / 2 + LINE(3, 9872, 1306);
  tmp1 = Acc;
  Acc = LINE(1, 8561, 1) / 2 + tmp1 / 2;
  WRITE_LINE(1, 8561) = Acc;
  Acc = WRITE_LINE(1, 8561) + tmp2;
  WRITE_LINE(8, 14810) = Acc;
  *out_left = tmp5;
  *out_right = tmp3;
}
```

It should be reasonably fast (compared to the naive emulation).

#### Usage

The `all-effects.h` file was generated with

```shell
cat midiverb.rom midifex.rom > both.rom
python3 disasm.py -d all-effects.h -i both.rom
```

Midiverb emulator will by default use the decompiled effects if no ROMs are spcified.


### Midiverb VST3 plugin

There is [a plugin using the JUCE library](MidiverbPlugin/) that works very much like `all-effects-test` but can be run as a VST3 plugin with realtime parameters. This plugin was generated using Claude Code.

There are precompiled binaries in releases.

It could be compiled also for Mac but I don't have a Mac.


## Supported ROMs

The effect ROM is not distributed with this program and you have to obtain it yourself. If you own a MIDIVERB/MIDIFEX unit and don't want to dump the EEPROM yourself, you might look for a synthesizer rom archive.

This program was tested with the following roms:

| MD5SUM | ROM name |
|---|---|
| 11a460c8e64d3325411bba0c11a2ae49  | midiverb.rom |
| f06003307a93ec09c637146ecaa17948  | midifex.rom |
| d503f74c239917b9888f247f979509ec  | midiverb2.rom |
