  /* Fill in the arguments.  */
  for (i = 0; i < nurl; i++, optind++)
    {
      char *rewritten = rewrite_url_maybe (argv[optind]);
      if (rewritten)
	{
	  printf ("Converted %s to %s\n", argv[optind], rewritten);
