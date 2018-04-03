 #define print_to_socket(fh, ...)                                               \
   do {                                                                         \
     if (fprintf(fh, __VA_ARGS__) < 0) {                                        \
-      char errbuf[1024];                                                       \
       WARNING("handle_putnotif: failed to write to socket #%i: %s",            \
-              fileno(fh), sstrerror(errno, errbuf, sizeof(errbuf)));           \
+              fileno(fh), STRERRNO);                                           \
       return -1;                                                               \
     }                                                                          \
     fflush(fh);                                                                \
