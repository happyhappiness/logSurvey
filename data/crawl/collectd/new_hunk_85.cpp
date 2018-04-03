#define print_to_socket(fh, ...)                                               \
  do {                                                                         \
    if (fprintf(fh, __VA_ARGS__) < 0) {                                        \
      WARNING("handle_putnotif: failed to write to socket #%i: %s",            \
              fileno(fh), STRERRNO);                                           \
      return -1;                                                               \
    }                                                                          \
    fflush(fh);                                                                \
