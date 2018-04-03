	hier_strings[al->hier.code]);
}

static void
accessLogOpen(const char *fname)
{
    assert(fname);
    xstrncpy(LogfileName, fname, SQUID_MAXPATHLEN);
    LogfileFD = file_open(LogfileName, O_WRONLY | O_CREAT, NULL, NULL);
    if (LogfileFD == DISK_ERROR) {
	debug(50, 0) ("%s: %s\n", LogfileName, xstrerror());
	fatal("Cannot open logfile.");
    }
    LogfileStatus = LOG_ENABLE;
}

#define SKIP_BASIC_SZ 6
void
accessLogLog(AccessLogEntry * al)
