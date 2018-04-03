#define print_to_socket(fh, ...)                                               \
  do {                                                                         \
    if (fprintf(fh, __VA_ARGS__) < 0) {                                        \
      char errbuf[1024];                                                       \
      WARNING("cmd_handle_getval: failed to write to socket #%i: %s",          \
              fileno(fh), sstrerror(errno, errbuf, sizeof(errbuf)));           \
      return -1;                                                               \
    }                                                                          \
    fflush(fh);                                                                \