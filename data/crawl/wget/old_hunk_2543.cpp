  if (opt.remove_listing)
    {
      if (unlink (lf))
	logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
      else
	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), lf);
    }
  xfree (lf);
  con->cmd &= ~DO_LIST;
