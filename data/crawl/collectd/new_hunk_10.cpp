
  fh = fopen(file, "r");
  if (fh == NULL) {
    fprintf(stderr, "Failed to open types database `%s': %s.\n", file,
            STRERRNO);
    ERROR("Failed to open types database `%s': %s", file, STRERRNO);
    return -1;
  }

