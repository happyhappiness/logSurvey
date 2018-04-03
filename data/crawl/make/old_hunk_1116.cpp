    {
      int i;
      fprintf(stderr,
              "process_easy() failed failed to launch process (e=%d)\n",
              process_last_err(hPID));
      for (i = 0; argv[i]; i++)
          fprintf(stderr, "%s ", argv[i]);
      fprintf(stderr, "\nCounted %d args in failed launch\n", i);
      exit(EXIT_FAILURE);
    }

