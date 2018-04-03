  }

  if (fh == NULL) {
    fprintf(stderr, "logfile plugin: fopen (%s) failed: %s\n", log_file,
            STRERRNO);
  } else {
    if (print_timestamp)
      fprintf(fh, "[%s] %s%s\n", timestamp_str, level_str, msg);
