	}
      logprintf (LOG_VERBOSE, _("%s (%s) - `%s' saved [%ld]\n\n"),
		 tms, tmrate, locf, len);
      logprintf (LOG_NONVERBOSE, "%s URL: %s [%ld] -> \"%s\" [%d]\n",
		 tms, u->url, len, locf, count);

      if ((con->cmd & DO_LIST))
	/* This is a directory listing file. */
