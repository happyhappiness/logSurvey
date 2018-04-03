
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
static void
log_get_start(const cacheinfo * obj, StoreEntry * sentry)
