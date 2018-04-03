
/* start convert squid.conf file to processed format */
static void
squid_get_start(cacheinfo * obj, StoreEntry * sentry)
{
    squid_read_data_t *data;

    data = xcalloc(1, sizeof(squid_read_data_t));
    data->sentry = sentry;
    data->fd = file_open((char *) ConfigFile, NULL, O_RDONLY);
    storeAppendPrintf(sentry, open_bracket);
    file_walk(data->fd, (FILE_WALK_HD) squidReadEndHandler, (void *) data,
	(FILE_WALK_LHD) squidReadHandler, (void *) data);
