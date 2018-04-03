
      output_stream = NULL;

      /* The directory prefix for opt.metalink_over_http is handled by
         src/url.c (url_file_name), do not add it a second time.  */
      if (!metalink->origin && opt.dir_prefix && strlen (opt.dir_prefix))
        filename = aprintf ("%s/%s", opt.dir_prefix, mfile->name);
      else
        filename = xstrdup (mfile->name);

      DEBUGP (("Processing metalink file %s...\n", quote (mfile->name)));

      /* Resources are sorted by priority.  */
