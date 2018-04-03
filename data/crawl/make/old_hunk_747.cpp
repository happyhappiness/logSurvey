#endif
    {
#ifdef	HAVE_GETCWD
      perror_with_name ("getcwd: ", "");
#else
      error (NILF, "getwd: %s", current_directory);
#endif
