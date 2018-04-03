  con->target = old_target;

  if (err == RETROK)
    *f = ftp_parse_ls (lf, con->rs);
  else
    *f = NULL;
  if (opt.remove_listing)
    {
      if (unlink (lf))
        logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
      else
        logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), lf);
    }
  xfree (lf);
  con->cmd &= ~DO_LIST;
  return err;
