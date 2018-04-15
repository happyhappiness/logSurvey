
    if ((pid = fork()) == -1) {
      /* error */
      fprintf(stderr, "fork: %s", STRERRNO);
      return 1;
    } else if (pid != 0) {
      /* parent */
