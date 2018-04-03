
  secs = ptimer_measure (timer) / 1000;
  ptimer_destroy (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %.*f seconds.\n"),
	     file_count, secs < 10 ? 3 : 1, secs);
}

static void write_backup_file (const char *, downloaded_file_t);
