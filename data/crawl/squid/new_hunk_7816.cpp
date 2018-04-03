     int size_unused;
     log_read_data_t *data;
{
    storeAppendPrintf(data->sentry, "{%s}\n", buf);
    return 0;
}

