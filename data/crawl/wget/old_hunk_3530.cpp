
      if (skipped)
	{
	  logputs (LOG_VERBOSE, "\n      "); /* leave spacing untranslated */
	  logprintf (LOG_VERBOSE, _("[ skipping %dK ]"),
		     (int) (skipped / 1024));
	}

      logprintf (LOG_VERBOSE, "\n%5ldK", skipped / 1024);
