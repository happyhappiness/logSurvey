#define print_to_socket(fh, ...)                                               \
  do {                                                                         \
    if (fprintf(fh, __VA_ARGS__) < 0) {                                        \
      WARNING("handle_listval: failed to write to socket #%i: %s", fileno(fh), \
              STRERRNO);                                                       \
      free_everything_and_return(CMD_ERROR);                                   \
    }                                                                          \
    fflush(fh);                                                                \
