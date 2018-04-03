
/* squid convert handler */
/* call for each line in file, use fileWalk routine */
static int
squidReadHandler(int fd_unused, const char *buf, int size_unused, squid_read_data_t * data)
{
    storeAppendPrintf(data->sentry, "{\"%s\"}\n", buf);
    return 0;
}

/* squid convert end handler */
/* call when a walk is completed or error. */
static void
squidReadEndHandler(int fd_unused, int errflag_unused, squid_read_data_t * data)
{
    storeAppendPrintf(data->sentry, close_bracket);
    storeComplete(data->sentry);
    file_close(data->fd);
    safe_free(data);
}


