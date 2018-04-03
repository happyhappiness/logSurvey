    {
      const char *txt_addr = pretty_print_address (ip);
      if (print && 0 != strcmp (print, txt_addr))
	logprintf (LOG_VERBOSE,
		   _("Connecting to %s|%s|:%d... "), print, txt_addr, port);
      else
	logprintf (LOG_VERBOSE, _("Connecting to %s:%d... "), txt_addr, port);
    }
