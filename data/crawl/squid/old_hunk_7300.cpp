    data->sentry = sentry;
    data->fd = file_open(ConfigFile, NULL, O_RDONLY, NULL, NULL);
    storeAppendPrintf(sentry, open_bracket);
    file_walk(data->fd, squidReadEndHandler, data,
	squidReadHandler, data);
}


