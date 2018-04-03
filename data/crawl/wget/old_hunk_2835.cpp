    {
      fprintf (stderr, _("%s: Cannot read %s (%s).\n"), exec_name,
	       file, strerror (errno));
      return 1;			/* not a fatal error */
    }
  enable_tilde_expansion = 1;
  ln = 1;
  while ((line = read_whole_line (fp)) != NULL)
    {
