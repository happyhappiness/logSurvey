  }

  if (fh == NULL) {
    fprintf(stderr, "log_logstash plugin: fopen (%s) failed: %s\n", log_file,
            STRERRNO);
  } else {
    fprintf(fh, "%s\n", buf);
    if (do_close) {
