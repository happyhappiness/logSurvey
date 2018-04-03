
  /* Fill in the arguments.  */
  url = alloca_array (char *, nurl + 1);
  for (i = 0; i < nurl; i++, optind++)
    {
      char *rewritten = rewrite_shorthand_url (argv[optind]);
