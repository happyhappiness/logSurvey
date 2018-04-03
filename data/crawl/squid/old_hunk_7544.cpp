
/* squid convert handler */
/* call for each line in file, use fileWalk routine */
static int squidReadHandler(fd_unused, buf, size_unused, data)
     int fd_unused;
     char *buf;
     int size_unused;
     squid_read_data_t *data;
{
    storeAppendPrintf(data->sentry, "{\"%s\"}\n", buf);
    return 0;
}

/* squid convert end handler */
/* call when a walk is completed or error. */
static void squidReadEndHandler(fd_unused, errflag_unused, data)
     int fd_unused;
     int errflag_unused;
     squid_read_data_t *data;
{
    storeAppendPrintf(data->sentry, close_bracket);
    storeComplete(data->sentry);
