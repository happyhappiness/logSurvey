	fatal(tmp_error_buf);
    }
    debug(20, 3, "data->log %d is now '%s'\n", fileno(data->log), swaplog_file);
    if (data->fast_mode)
	debug(20, 1, "Rebuilding in FAST MODE.\n");

    memset(data->line_in, '\0', 4096);

    /* Start reading the log file */
    runInBackground("storeRebuild",
	(int (*)(void *)) storeDoRebuildFromDisk,
	data,
	(void (*)(void *)) storeRebuiltFromDisk);
}

/* return current swap size in kilo-bytes */
