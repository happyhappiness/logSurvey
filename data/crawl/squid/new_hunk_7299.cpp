
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


