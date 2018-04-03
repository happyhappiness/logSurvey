{
    static char tempbuf[MAX_LINELEN];
    tempbuf[0] = '\0';
    storeAppendPrintf(data->sentry, "{\"%s\"}\n", buf);
    return 0;
}

