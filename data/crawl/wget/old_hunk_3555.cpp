  uerr_t err;
  struct stat st;

  if (!u->local)
    u->local = url_filename (u);

  if (opt.noclobber && file_exists_p (u->local))
    {
      logprintf (LOG_VERBOSE,
		 _("File `%s' already there, not retrieving.\n"), u->local);
      /* If the file is there, we suppose it's retrieved OK.  */
      return RETROK;
    }

  /* Remove it if it's a link.  */
  remove_link (u->local);
  if (!opt.output_document)
    locf = u->local;
  else
    locf = opt.output_document;

