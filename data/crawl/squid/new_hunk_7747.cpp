     int size_unused;
     squid_read_data_t *data;
{
    storeAppendPrintf(data->sentry, "{\"%s\"}\n", buf);
    return 0;
}
