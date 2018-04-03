	storeComplete(sentry);
	return;
    }
    data = xcalloc(1, sizeof(log_read_data_t));
    data->sentry = sentry;
    storeAppendPrintf(sentry, "{\n");
    file_walk(obj->logfile_fd, (FILE_WALK_HD) logReadEndHandler,
