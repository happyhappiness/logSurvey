    }
}


/* generate logfile status information */
void
log_status_get(StoreEntry * sentry)
{
    if (LogfileStatus == LOG_ENABLE) {
	storeAppendPrintf(sentry, "{\"Logfile is Enabled. Filename: %s\"}\n",
	    LogfileName);
    } else {
	storeAppendPrintf(sentry, "{\"Logfile is Disabled.\"}\n");
    }
}



/* log convert handler */
/* call for each line in file, use fileWalk routine */
static void
logReadHandler(int fd_unused, const char *buf, int size_unused, void *data)
{
    log_read_data_t *ctrl = data;
    storeAppendPrintf(ctrl->sentry, "{%s}\n", buf);
}

/* log convert end handler */
/* call when a walk is completed or error. */
static void
logReadEndHandler(int fd, int errflag_unused, void *data)
{
    log_read_data_t *ctrl = data;
    storeAppendPrintf(ctrl->sentry, close_bracket);
    storeComplete(ctrl->sentry);
    safe_free(ctrl);
    file_close(fd);
}

/* start converting logfile to processed format */
void
log_get_start(StoreEntry * sentry)
{
    log_read_data_t *data = NULL;
    int fd;

    if (LogfileStatus == LOG_DISABLE) {
	/* Manufacture status when logging is disabled */
	log_status_get(sentry);
	storeComplete(sentry);
	return;
    }
    fd = file_open(LogfileName, O_RDONLY, NULL, NULL);
    if (fd < 0) {
	debug(50, 0) ("Cannot open logfile: %s: %s\n",
	    LogfileName, xstrerror());
	return;
    }
    data = xcalloc(1, sizeof(log_read_data_t));
    data->sentry = sentry;
    storeAppendPrintf(sentry, "{\n");
    file_walk(fd,
	logReadEndHandler,
	data,
	logReadHandler,
	data);
    return;
}


/* squid convert handler */
/* call for each line in file, use fileWalk routine */
static void
squidReadHandler(int fd_unused, const char *buf, int size_unused, void *data)
{
    squid_read_data_t *ctrl = data;
    storeAppendPrintf(ctrl->sentry, "{\"%s\"}\n", buf);
}

/* squid convert end handler */
/* call when a walk is completed or error. */
static void
squidReadEndHandler(int fd_unused, int errflag_unused, void *data)
{
    squid_read_data_t *ctrl = data;
    storeAppendPrintf(ctrl->sentry, close_bracket);
    storeComplete(ctrl->sentry);
    file_close(ctrl->fd);
    safe_free(ctrl);
}


/* start convert squid.conf file to processed format */
void
squid_get_start(StoreEntry * sentry)
{
    squid_read_data_t *data;

    data = xcalloc(1, sizeof(squid_read_data_t));
    data->sentry = sentry;
    data->fd = file_open(ConfigFile, O_RDONLY, NULL, NULL);
    storeAppendPrintf(sentry, open_bracket);
    file_walk(data->fd, squidReadEndHandler, data, squidReadHandler, data);
}

void
server_list(StoreEntry * sentry)
{
