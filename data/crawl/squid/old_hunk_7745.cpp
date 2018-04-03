     int errflag_unused;
     log_read_data_t *data;
{
    storeAppendPrintf(data->sentry, "}\n");
    storeComplete(data->sentry);
    safe_free(data);
}
