CC=gcc
midiverb: midiverb.c utils.h wav.h args.h dasp16.h lfo.h rom.h decompiled-midiverb.h decompiled-midifex.h decompiled-midiverb2.h
	$(CC) midiverb.c -o midiverb -Wall -lsndfile
clean:
	-rm midiverb
