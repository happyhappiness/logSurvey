    }
    *object = obj;
}

void
stat_rotate_log(void)
{
    int i;
    LOCAL_ARRAY(char, from, MAXPATHLEN);
    LOCAL_ARRAY(char, to, MAXPATHLEN);
    char *fname = NULL;
    struct stat sb;

    if ((fname = LogfileName) == NULL)
	return;
#ifdef S_ISREG
    if (stat(fname, &sb) == 0)
	if (S_ISREG(sb.st_mode) == 0)
	    return;
#endif

    debug(18, 1) ("stat_rotate_log: Rotating\n");

    /* Rotate numbers 0 through N up one */
    for (i = Config.Log.rotateNumber; i > 1;) {
	i--;
	sprintf(from, "%s.%d", fname, i - 1);
	sprintf(to, "%s.%d", fname, i);
	rename(from, to);
    }
    /* Rotate the current log to .0 */
    if (Config.Log.rotateNumber > 0) {
	sprintf(to, "%s.%d", fname, 0);
	rename(fname, to);
    }
    /* Close and reopen the log.  It may have been renamed "manually"
     * before HUP'ing us. */
    file_close(LogfileFD);
    LogfileFD = file_open(fname, O_WRONLY | O_CREAT, NULL, NULL);
    if (LogfileFD == DISK_ERROR) {
	debug(18, 0) ("stat_rotate_log: Cannot open logfile: %s\n", fname);
	LogfileStatus = LOG_DISABLE;
	fatal("Cannot open logfile.");
    }
}

void
statCloseLog(void)
{
    file_close(LogfileFD);
}
