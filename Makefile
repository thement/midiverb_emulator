CC=gcc
midiverb: midiverb.c utils.h wav.h args.h dasp16.h lfo.h rom.h decompiled-midiverb.h decompiled-midifex.h decompiled-midiverb2.h
	$(CC) midiverb.c -o midiverb -Wall -lsndfile

# Generate float versions of the effect headers
decompiled-midiverb-float.h: roms/midiverb.rom disasm.py
	python3 disasm.py -d $@ -f -p midiverb_f_ $<

decompiled-midifex-float.h: roms/midifex.rom disasm.py
	python3 disasm.py -d $@ -f -p midifex_f_ $<

decompiled-midiverb2-float.h: roms/midiverb2.rom disasm.py
	python3 disasm.py -d $@ -f -2 -p midiverb2_f_ $<

float-effects: decompiled-midiverb-float.h decompiled-midifex-float.h decompiled-midiverb2-float.h

clean:
	-rm midiverb
