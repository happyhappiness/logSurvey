  char *env_wgetrc, *user_wgetrc;
  int i;

#ifdef __VMS
  printf (_("GNU Wget %s built on VMS %s %s.\n\n"),
   version_string, vms_arch(), vms_vers());
#else /* def __VMS */
  printf (_("GNU Wget %s built on %s.\n\n"), version_string, OS_TYPE);
#endif /* def __VMS */
  /* compiled_features is a char*[]. We limit the characters per
     line to MAX_CHARS_PER_LINE and prefix each line with a constant
     number of spaces for proper alignment. */
