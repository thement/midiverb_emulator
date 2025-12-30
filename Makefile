CC=gcc
all: midiverb all-effects-test
midiverb: midiverb.c utils.h wav.h args.h dasp16.h lfo.h rom.h
	$(CC) midiverb.c -o midiverb -Wall -Wno-unused-variable -lsndfile
all-effects-test: all-effects-test.c all-effects.h utils.h
	$(CC) all-effects-test.c -o all-effects-test -Wall -Wno-unused-variable -lsndfile -lm
