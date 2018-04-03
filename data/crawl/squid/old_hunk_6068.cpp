void
accessLogRotate(void)
{
    int i;
    LOCAL_ARRAY(char, from, MAXPATHLEN);
    LOCAL_ARRAY(char, to, MAXPATHLEN);
    char *fname = NULL;
    struct stat sb;
#if FORW_VIA_DB
    fvdbClear();
#endif
    if ((fname = LogfileName) == NULL)
	return;
#ifdef S_ISREG
    if (stat(fname, &sb) == 0)
	if (S_ISREG(sb.st_mode) == 0)
	    return;
#endif
    debug(46, 1) ("accessLogRotate: Rotating\n");
    /* Rotate numbers 0 through N up one */
    for (i = Config.Log.rotateNumber; i > 1;) {
	i--;
	snprintf(from, MAXPATHLEN, "%s.%d", fname, i - 1);
	snprintf(to, MAXPATHLEN, "%s.%d", fname, i);
	xrename(from, to);
    }
    /* Rotate the current log to .0 */
    file_close(LogfileFD);	/* always close */
    if (Config.Log.rotateNumber > 0) {
	snprintf(to, MAXPATHLEN, "%s.%d", fname, 0);
	xrename(fname, to);
    }
    /* Reopen the log.  It may have been renamed "manually" */
    LogfileFD = file_open(fname, O_WRONLY | O_CREAT);
    if (LogfileFD == DISK_ERROR) {
	debug(46, 0) ("accessLogRotate: Cannot open logfile: %s\n", fname);
	LogfileStatus = LOG_DISABLE;
	fatalf("Cannot open %s: %s", fname, xstrerror());
    }
}

void
accessLogClose(void)
{
    file_close(LogfileFD);
}

void
