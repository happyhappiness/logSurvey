    }

  wtimer_update (timer);
  msecs = wtimer_read (timer);
  wtimer_delete (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %.2f seconds.\n"),
	     file_count, (double)msecs / 1000);
}

static void write_backup_file PARAMS ((const char *, downloaded_file_t));
