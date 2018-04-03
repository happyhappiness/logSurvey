  secs = ptimer_measure (timer);
  ptimer_destroy (timer);
  logprintf (LOG_VERBOSE, _("Converted %d files in %s seconds.\n"),
	     file_count, print_decimal (secs));
}

static void write_backup_file (const char *, downloaded_file_t);
static const char *replace_attr (const char *, int, FILE *, const char *);
static const char *replace_attr_refresh_hack (const char *, int, FILE *,
					      const char *, int);
static char *local_quote_string (const char *);
static char *construct_relative (const char *, const char *);

