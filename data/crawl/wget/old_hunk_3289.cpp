  al = lookup_host (host, flags | LH_SILENT | LH_PASSIVE);
  if (al == NULL)
    {
      logprintf (LOG_NOTQUIET,
		 _("Unable to convert `%s' to a bind address.  Reverting to ANY.\n"),
		 opt.bind_address);
      return 0;
    }

