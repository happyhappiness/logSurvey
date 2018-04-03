     int errflag_unused;
     log_read_data_t *data;
{
    storeAppendPrintf(data->sentry, close_bracket);
    storeComplete(data->sentry);
    safe_free(data);
}
