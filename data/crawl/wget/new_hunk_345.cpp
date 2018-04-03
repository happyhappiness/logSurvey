  /* All user options have now been processed, so it's now safe to do
     interoption dependency checks. */

  if (opt.noclobber && opt.convert_links)
    {
      fprintf (stderr,
               _("Both --no-clobber and --convert-links were specified,"
                 "only --convert-links will be used.\n"));
      opt.noclobber = false;
    }

  if (opt.reclevel == 0)
      opt.reclevel = INFINITE_RECURSION; /* see recur.h for commentary */

