
#define print_to_socket(fh, ...)                                               \
  if (fprintf(fh, __VA_ARGS__) < 0) {                                          \
    WARNING("handle_getthreshold: failed to write to socket #%i: %s",          \
            fileno(fh), STRERRNO);                                             \
    return -1;                                                                 \
  }

