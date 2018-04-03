

/* generate logfile status information */
static void
log_status_get(cacheinfo * obj, StoreEntry * sentry)
{
    if (obj->logfile_status == LOG_ENABLE) {
	storeAppendPrintf(sentry, "{\"Logfile is Enabled. Filename: %s\"}\n",
