
/* log convert handler */
/* call for each line in file, use fileWalk routine */
static int logReadHandler(fd_unused, buf, size_unused, data)
     int fd_unused;
     char *buf;
     int size_unused;
     log_read_data_t *data;
{
    storeAppendPrintf(data->sentry, "{%s}\n", buf);
    return 0;
}

/* log convert end handler */
/* call when a walk is completed or error. */
static void logReadEndHandler(fd, errflag_unused, data)
     int fd;
     int errflag_unused;
     log_read_data_t *data;
{
    storeAppendPrintf(data->sentry, close_bracket);
    storeComplete(data->sentry);
