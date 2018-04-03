static void
print_length (wgint size, wgint start, int authoritative)
{
  logprintf (LOG_VERBOSE, _("Length: %s"), number_to_static_string (size));
  if (size >= 1024)
    logprintf (LOG_VERBOSE, " (%s)", human_readable (size));
  if (start > 0)
    {
      if (start >= 1024)
	logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
		   number_to_static_string (size - start),
		   human_readable (size - start));
      else
	logprintf (LOG_VERBOSE, _(", %s remaining"),
		   number_to_static_string (size - start));
    }
  logputs (LOG_VERBOSE, !authoritative ? _(" (unauthoritative)\n") : "\n");
}
