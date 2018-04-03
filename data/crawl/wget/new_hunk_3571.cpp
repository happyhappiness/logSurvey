    logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));

  /* Determine the local filename.  */
  if (local_file && *local_file)
    hstat.local_file = local_file;
  else if (local_file)
    {
      *local_file = url_filename (u);
      hstat.local_file = local_file;
    }
  else
    {
      dummy = url_filename (u);
      hstat.local_file = &dummy;
    }

  if (!opt.output_document)
    locf = *hstat.local_file;
  else
    locf = opt.output_document;

  hstat.referer = referer;

  filename_len = strlen (*hstat.local_file);
  filename_plus_orig_suffix = alloca (filename_len + sizeof (".orig"));

  if (opt.noclobber && file_exists_p (*hstat.local_file))
    {
      /* If opt.noclobber is turned on and file already exists, do not
	 retrieve the file */
      logprintf (LOG_VERBOSE, _("\
File `%s' already there, will not retrieve.\n"), *hstat.local_file);
      /* If the file is there, we suppose it's retrieved OK.  */
      *dt |= RETROKF;

      /* #### Bogusness alert.  */
      /* If its suffix is "html" or "htm", assume text/html.  */
      if (((suf = suffix (*hstat.local_file)) != NULL)
	  && (!strcmp (suf, "html") || !strcmp (suf, "htm")))
	*dt |= TEXTHTML;
      xfree (suf);

      FREE_MAYBE (dummy);
      return RETROK;
    }

