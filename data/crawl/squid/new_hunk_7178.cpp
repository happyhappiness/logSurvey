	debug(18, 1) ("log_append: File write failed.\n");
}

void
log_enable(StoreEntry * sentry)
{
    if (LogfileStatus == LOG_DISABLE) {
	LogfileStatus = LOG_ENABLE;
	/* open the logfile */
	LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
	if (LogfileFD == DISK_ERROR) {
	    debug(18, 0) ("Cannot open logfile: %s\n", LogfileName);
	    LogfileStatus = LOG_DISABLE;
	}
    }
}

void
log_disable(StoreEntry * sentry)
{
    if (LogfileStatus == LOG_ENABLE)
	file_close(LogfileFD);
    LogfileStatus = LOG_DISABLE;
}

void
log_clear(StoreEntry * sentry)
{
    /* what should be done here. Erase file ??? or move it to another name?  At the moment, just erase it.  bug here need to be fixed. what if there are still data in memory. Need flush here */
    if (LogfileStatus == LOG_ENABLE)
	file_close(LogfileFD);
    unlink(LogfileName);
    /* reopen it anyway */
    LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
    if (LogfileFD == DISK_ERROR) {
	debug(18, 0) ("Cannot open logfile: %s\n", LogfileName);
	LogfileStatus = LOG_DISABLE;
    }
    /* at the moment, store one char to make a storage manager happy */
    storeAppendPrintf(sentry, " ");
