  char *env_wgetrc, *user_wgetrc;
  int i;

  printf (_("GNU Wget %s built on %s.\n\n"), version_string, OS_TYPE);
  /* compiled_features is a char*[]. We limit the characters per
     line to MAX_CHARS_PER_LINE and prefix each line with a constant
     number of spaces for proper alignment. */
