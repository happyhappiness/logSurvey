}


void cached_error_entry(entry, type, msg)
     StoreEntry *entry;
     int type;
     char *msg;
{
    int index;
    if (type < ERR_MIN || type > ERR_MAX)
	fatal_dump("cached_error_entry: type out of range.");
    index = (int) (type - ERR_MIN);
    sprintf(tmp_error_buf, CACHED_ERROR_MSG_P1,
	entry->url,
	entry->url,
	ErrorData[index].shrt);
    if (msg) {
	sprintf(tbuf, CACHED_ERROR_MSG_P2, msg);
	strcat(tmp_error_buf, tbuf);
    }
    sprintf(tbuf, CACHED_ERROR_MSG_P3,
	ErrorData[index].lng,
	version_string,
	getMyHostname());
    strcat(tmp_error_buf, tbuf);
