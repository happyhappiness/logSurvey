
  secs = ptimer_measure (timer) / 1000;
  ptimer_destroy (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %s seconds.\n"),
	     file_count, print_decimal (secs));
}

static void write_backup_file (const char *, downloaded_file_t);