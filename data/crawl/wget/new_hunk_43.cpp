    {
      if (HYPHENP (file))
        {
          stdlogfp = stdout;
          logfp = stdlogfp;
        }
      else
        {
          filelogfp = fopen (file, appendp ? "a" : "w");
          if (!filelogfp)
            {
              fprintf (stderr, "%s: %s: %s\n", exec_name, file, strerror (errno));
              exit (WGET_EXIT_GENERIC_ERROR);
            }
          logfp = filelogfp;
        }
    }
  else
