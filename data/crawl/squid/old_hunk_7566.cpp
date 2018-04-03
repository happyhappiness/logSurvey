    }
    /* Close and reopen the log.  It may have been renamed "manually"
     * before HUP'ing us. */
    file_close(CacheInfo->logfile_fd);
    CacheInfo->logfile_fd = file_open(fname, NULL, O_WRONLY | O_CREAT);
    if (CacheInfo->logfile_fd == DISK_ERROR) {
	debug(18, 0, "stat_rotate_log: Cannot open logfile: %s\n", fname);
	CacheInfo->logfile_status = LOG_DISABLE;
	fatal("Cannot open logfile.");
    }
    CacheInfo->logfile_access = file_write_lock(CacheInfo->logfile_fd);
}

void statCloseLog()
{
    file_close(CacheInfo->logfile_fd);
}
