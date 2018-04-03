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