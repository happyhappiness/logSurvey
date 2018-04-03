    }
    /* Close and reopen the log.  It may have been renamed "manually"
     * before HUP'ing us. */
    file_close(HTTPCacheInfo->logfile_fd);
    HTTPCacheInfo->logfile_fd = file_open(fname, NULL, O_WRONLY | O_CREAT);
    if (HTTPCacheInfo->logfile_fd == DISK_ERROR) {
	debug(18, 0, "stat_rotate_log: Cannot open logfile: %s\n", fname);
	HTTPCacheInfo->logfile_status = LOG_DISABLE;
	fatal("Cannot open logfile.");
    }
    HTTPCacheInfo->logfile_access = file_write_lock(HTTPCacheInfo->logfile_fd);
}

void statCloseLog()
{
    file_close(HTTPCacheInfo->logfile_fd);
}
