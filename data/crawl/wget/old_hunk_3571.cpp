    logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));

  /* Determine the local filename.  */
  if (!u->local)
    u->local = url_filename (u->proxy ? u->proxy : u);

  if (!opt.output_document)
    locf = u->local;
  else
    locf = opt.output_document;

  filename_len = strlen (u->local);
  filename_plus_orig_suffix = alloca (filename_len + sizeof (".orig"));

  if (opt.noclobber && file_exists_p (u->local))
    {
      /* If opt.noclobber is turned on and file already exists, do not
	 retrieve the file */
      logprintf (LOG_VERBOSE, _("\
File `%s' already there, will not retrieve.\n"), u->local);
      /* If the file is there, we suppose it's retrieved OK.  */
      *dt |= RETROKF;

      /* #### Bogusness alert.  */
      /* If its suffix is "html" or (yuck!) "htm", we suppose it's
	 text/html, a harmless lie.  */
      if (((suf = suffix (u->local)) != NULL)
	  && (!strcmp (suf, "html") || !strcmp (suf, "htm")))
	*dt |= TEXTHTML;
      xfree (suf);
      /* Another harmless lie: */
      return RETROK;
    }

