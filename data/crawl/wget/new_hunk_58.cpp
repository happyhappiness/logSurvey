
      DEBUGP (("Processing metalink file %s...\n", quote (mfile->name)));

      /* Enforce libmetalink's metalink_check_safe_path().  */
      basename = get_metalink_basename (filename);
      safename = metalink_check_safe_path (filename) ? filename : basename;

      if (filename != safename)
        logprintf (LOG_NOTQUIET,
                   _("Unsafe metalink file %s. Stripping directory...\n"),
                   quote (filename));

      if (!basename)
        {
          logprintf (LOG_NOTQUIET,
                     _("Rejecting metalink file. Invalid basename.\n"));
          xfree (filename);
          continue;
        }

      /* Resources are sorted by priority.  */
      for (mres_ptr = mfile->resources; *mres_ptr && !skip_mfile; mres_ptr++)
        {
