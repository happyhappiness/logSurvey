     char *message;
{
#if HAVE_SYSLOG
    if (opt_syslog_enable)
	syslog(LOG_ALERT, message);
#endif
    fprintf(debug_log, "FATAL: %s\n", message);