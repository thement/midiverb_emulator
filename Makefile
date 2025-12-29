CC=gcc
all: midiverb all-effects-test
midiverb: midiverb.c utils.h wav.h args.h dasp16.h rom.h
	$(CC) midiverb.c -o midiverb -Wall -lsndfile
all-effects-test: all-effects-test.c all-effects.h utils.h
	$(CC) all-effects-test.c -o all-effects-test -Wall -Wno-unused-variable -lsndfile -lm
