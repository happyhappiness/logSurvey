  if (!con->target)
    con->target = url_file_name (u);

  if (opt.noclobber && file_exists_p (con->target))
    {
      logprintf (LOG_VERBOSE,
                 _("File `%s' already there; not retrieving.\n"), con->target);
