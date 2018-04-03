
/* log convert handler */
/* call for each line in file, use fileWalk routine */
static int
logReadHandler(int fd_unused, const char *buf, int size_unused, log_read_data_t * data)
{
    storeAppendPrintf(data->sentry, "{%s}\n", buf);
    return 0;
}

/* log convert end handler */
/* call when a walk is completed or error. */
static void
logReadEndHandler(int fd, int errflag_unused, log_read_data_t * data)
{
    storeAppendPrintf(data->sentry, close_bracket);
    storeComplete(data->sentry);
    safe_free(data);
    file_close(fd);
}



/* start converting logfile to processed format */
static void
log_get_start(const cacheinfo * obj, StoreEntry * sentry)
