      free_urlpos (urls);
    }

  wtimer_update (timer);
  secs = wtimer_read (timer) / 1000;
  wtimer_delete (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %.*f seconds.\n"),
	     file_count, secs < 10 ? 3 : 1, secs);
}
