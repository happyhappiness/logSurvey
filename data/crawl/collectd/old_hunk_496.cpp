
static void stderr_log (int severity, const char *msg)
{
	if (severity > log_level)
		return;

	fprintf (stderr, "%s\n", msg);
	return;
} /* void stderr_log (int, const char *) */
