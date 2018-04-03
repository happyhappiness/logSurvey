    data = (log_read_data_t *) xmalloc(sizeof(log_read_data_t));
    memset(data, '\0', sizeof(log_read_data_t));
    data->sentry = sentry;
    strcpy(tmp, open_bracket);
    storeAppend(sentry, tmp, 2);
    file_walk(obj->logfile_fd, (FILE_WALK_HD) logReadEndHandler,
	(void *) data, (FILE_WALK_LHD) logReadHandler, (void *) data);
    return;
