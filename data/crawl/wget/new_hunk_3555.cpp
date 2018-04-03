  uerr_t err;
  struct stat st;

  if (!con->target)
    con->target = url_filename (u);

  if (opt.noclobber && file_exists_p (con->target))
    {
      logprintf (LOG_VERBOSE,
		 _("File `%s' already there, not retrieving.\n"), con->target);
      /* If the file is there, we suppose it's retrieved OK.  */
      return RETROK;
    }

  /* Remove it if it's a link.  */
  remove_link (con->target);
  if (!opt.output_document)
    locf = con->target;
  else
    locf = opt.output_document;

