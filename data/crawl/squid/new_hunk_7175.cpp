

/* generate logfile status information */
void
log_status_get(StoreEntry * sentry)
{
    if (LogfileStatus == LOG_ENABLE) {
	storeAppendPrintf(sentry, "{\"Logfile is Enabled. Filename: %s\"}\n",
	    LogfileName);
    } else {
	storeAppendPrintf(sentry, "{\"Logfile is Disabled.\"}\n");
    }
