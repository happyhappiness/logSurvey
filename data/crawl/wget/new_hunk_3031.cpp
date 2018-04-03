}
#endif

static void
print_length (wgint size, wgint start, int authoritative)
{
  logprintf (LOG_VERBOSE, _("Length: %s"), with_thousand_seps (size));
  if (size >= 1024)
    logprintf (LOG_VERBOSE, " (%s)", human_readable (size));
  if (start > 0)
    {
      if (start >= 1024)
	logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
		   with_thousand_seps (size - start),
		   human_readable (size - start));
      else
	logprintf (LOG_VERBOSE, _(", %s remaining"),
		   with_thousand_seps (size - start));
    }
  if (!authoritative)
    logputs (LOG_VERBOSE, _(" (unauthoritative)\n"));
}

/* Retrieves a file with denoted parameters through opening an FTP
   connection to the server.  It always closes the data connection,
   and closes the control connection in case of error.  */
