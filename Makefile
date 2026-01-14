CC=gcc

midiverb: midiverb.c utils.h wav.h args.h dasp16.h lfo.h rom.h decompiled-midiverb.h decompiled-midifex.h decompiled-midiverb2.h
	$(CC) midiverb.c -o midiverb -Wall -lsndfile

# Generate decompiled effect files from ROMs
# Note: ROMs are not distributed, obtain them yourself (see README.md)
decompiled-midiverb.h: roms/midiverb.rom names-midiverb.h disasm.py
	python3 ./disasm.py roms/midiverb.rom -i -d $@ --prefix midiverb_ --names names-midiverb.h

decompiled-midifex.h: roms/midifex.rom names-midifex.h disasm.py
	python3 ./disasm.py roms/midifex.rom -i -d $@ --prefix midifex_ --names names-midifex.h

decompiled-midiverb2.h: roms/midiverb2.rom names-midiverb2.h disasm.py
	python3 ./disasm.py -2 roms/midiverb2.rom -i -d $@ --prefix midiverb2_ --names names-midiverb2.h

.PHONY: decompiled clean
decompiled: decompiled-midiverb.h decompiled-midifex.h decompiled-midiverb2.h

clean:
	-rm midiverb
