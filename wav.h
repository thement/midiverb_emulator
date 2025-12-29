void load_wav_file(const char *filename, int16_t **samples, sf_count_t *num_samples, int *sample_rate, int *channels) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(filename, SFM_READ, &sfinfo);
    if (!infile) {
        die("Failed to open input file: %s", sf_strerror(NULL));
    }

    *sample_rate = sfinfo.samplerate;
    *channels = sfinfo.channels;
    *num_samples = sfinfo.frames * sfinfo.channels;

    *samples = (int16_t *)malloc(*num_samples * sizeof(int16_t));
    if (!*samples) {
        sf_close(infile);
        die("Failed to allocate memory for input samples");
    }

    if (sf_read_short(infile, *samples, *num_samples) != *num_samples) {
        free(*samples);
        sf_close(infile);
        die("Failed to read samples from input file");
    }

    sf_close(infile);
}

void write_wav_file(const char *filename, int16_t *samples, sf_count_t num_samples, int sample_rate, int channels) {
    SF_INFO sfinfo;
    memset(&sfinfo, 0, sizeof(sfinfo));
    sfinfo.samplerate = sample_rate;
    sfinfo.channels = channels;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        die("Failed to open output file: %s", sf_strerror(NULL));
    }

    if (sf_write_short(outfile, samples, num_samples) != num_samples) {
        sf_close(outfile);
        die("Failed to write samples to output file");
    }

    sf_close(outfile);
}


