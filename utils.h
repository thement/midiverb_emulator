// Error handling functions
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

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
