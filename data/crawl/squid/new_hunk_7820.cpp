     int errflag_unused;
     squid_read_data_t *data;
{
    storeAppendPrintf(data->sentry, "}\n");
    storeComplete(data->sentry);
    file_close(data->fd);
    safe_free(data);
