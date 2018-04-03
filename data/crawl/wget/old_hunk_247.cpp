
  nurl = argc - optind;

  /* All user options have now been processed, so it's now safe to do
     interoption dependency checks. */

  if (opt.noclobber && opt.convert_links)
    {
      fprintf (stderr,
