  /* Print fetch message, if opt.verbose.  */
  if (opt.verbose)
    {
      logprintf (LOG_NOTQUIET, _("Saving to: %s\n"), 
                 HYPHENP (hs->local_file) ? quote ("STDOUT") : quote (hs->local_file));
    }
    
  /* This confuses the timestamping code that checks for file size.
