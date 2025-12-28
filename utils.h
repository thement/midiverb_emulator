#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

static inline void pexit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static inline void die(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

static inline void read_bytes(const char *path, int offset, int num_bytes, void *dest) {
    FILE *f = fopen(path, "rb");
    if (!f)
        die("Failed to open file '%s': %s", path, strerror(errno));

    if (fseek(f, offset, SEEK_SET) != 0)
        die("Failed to seek to 0x%x in '%s': %s", offset, path, strerror(errno));

    if (fread(dest, 1, num_bytes, f) != (size_t)num_bytes)
        die("Failed to read from file: %s", strerror(errno));

    fclose(f);
}
