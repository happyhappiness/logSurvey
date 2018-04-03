     int errflag_unused;
     log_read_data_t *data;
{
    storeAppend(data->sentry, close_bracket, strlen(close_bracket));
    storeComplete(data->sentry);
    safe_free(data);
}
