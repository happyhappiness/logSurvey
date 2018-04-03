     int size_unused;
     log_read_data_t *data;
{
    static char tempbuf[MAX_LINELEN];

    sprintf(tempbuf, "{%s}\n", buf);
    storeAppend(data->sentry,
	tempbuf,
	(int) strlen(tempbuf) % MAX_LINELEN);
    return 0;
}

