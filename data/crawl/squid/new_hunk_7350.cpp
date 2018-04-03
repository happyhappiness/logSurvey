	fatal(tmp_error_buf);
    }
    debug(20, 3, "data->log %d is now '%s'\n", fileno(data->log), swaplog_file);
    debug(20, 1, "Rebuilding in %s log.\n",
	store_rebuilding == STORE_REBUILDING_CLEAN ? "CLEAN" : "DIRTY");
    store_validating = store_rebuilding == STORE_REBUILDING_CLEAN ? 0 : 1;
    memset(data->line_in, '\0', 4096);
    data->speed = 50;
    /* Start reading the log file */
    if (opt_foreground_rebuild) {
	data->speed = 1 << 30;
