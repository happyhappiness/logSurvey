  /* All user options have now been processed, so it's now safe to do
     interoption dependency checks. */

  if (opt.noclobber && (opt.convert_links || opt.convert_file_only))
    {
      fprintf (stderr,
               opt.convert_links ?
                   _("Both --no-clobber and --convert-links were specified,"
                     " only --convert-links will be used.\n") :
                    _("Both --no-clobber and --convert-file-only were specified,"
                      " only --convert-file-only will be used.\n"));
      opt.noclobber = false;
    }

