
      output_stream = NULL;

      /* The directory prefix for opt.metalink_over_http is handled by
         src/url.c (url_file_name), do not add it a second time.  */
      if (!metalink->origin && opt.dir_prefix && strlen (opt.dir_prefix))
        filename = aprintf ("%s/%s", opt.dir_prefix, mfile->name);
      else
        filename = xstrdup (mfile->name);

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
