  /* Fill in the arguments.  */
  for (i = 0; i < nurl; i++, optind++)
    {
      char *irix4_cc_needs_this;
      STRDUP_ALLOCA (irix4_cc_needs_this, argv[optind]);
      url[i] = irix4_cc_needs_this;
    }
  url[i] = NULL;

