/* log convert handler */
/* call for each line in file, use fileWalk routine */
static int
logReadHandler(int fd_unused, const char *buf, int size_unused, log_read_data_t *data)
{
    storeAppendPrintf(data->sentry, "{%s}\n", buf);
    return 0;
