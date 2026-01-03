CC=gcc
midiverb: midiverb.c utils.h wav.h args.h dasp16.h lfo.h rom.h all-effects.h
	$(CC) midiverb.c -o midiverb -Wall -lsndfile
clean:
	-rm midiverb
