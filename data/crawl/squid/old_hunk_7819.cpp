{
    static char tempbuf[MAX_LINELEN];
    tempbuf[0] = '\0';
    sprintf(tempbuf, "{\"%s\"}\n", buf);
    storeAppend(data->sentry,
	tempbuf,
	(int) strlen(tempbuf) % MAX_LINELEN);
    return 0;
}

