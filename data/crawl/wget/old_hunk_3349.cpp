	  CLOSE (RBUF_FD (&con->rbuf));
	  rbuf_uninitialize (&con->rbuf);
	}
      logprintf (LOG_VERBOSE, _("%s (%s) - `%s' saved [%ld]\n\n"),
		 tms, tmrate, locf, len);
      if (!opt.verbose && !opt.quiet)
	{
	  /* Need to hide the password from the URL.  The `if' is here
