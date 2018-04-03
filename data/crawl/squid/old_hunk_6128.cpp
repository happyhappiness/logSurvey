fatal_common(const char *message)
{
#if HAVE_SYSLOG
    if (opt_syslog_enable)
	syslog(LOG_ALERT, "%s", message);
#endif
    fprintf(debug_log, "FATAL: %s\n", message);
    if (opt_debug_stderr && debug_log != stderr)
