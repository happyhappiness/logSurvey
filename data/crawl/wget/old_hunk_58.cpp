
      DEBUGP (("Processing metalink file %s...\n", quote (mfile->name)));

      /* Resources are sorted by priority.  */
      for (mres_ptr = mfile->resources; *mres_ptr && !skip_mfile; mres_ptr++)
        {
