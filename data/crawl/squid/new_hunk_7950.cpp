    }
    /* Close and reopen the log.  It may have been renamed "manually"
     * before HUP'ing us. */
    if (debug_log != stderr) {
	fclose(debug_log);
	debugOpenLog(debug_log_file);
    }
}
