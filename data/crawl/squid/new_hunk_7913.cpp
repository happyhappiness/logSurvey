
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
	SQUID_VERSION,
	getMyHostname());
    strcat(tmp_error_buf, tbuf);
    entry->mem_obj->abort_code = type;
    storeAbort(entry, tmp_error_buf);
}



char *cached_error_url(url, type, msg)
     char *url;
     int type;
     char *msg;
{
    int index;

    tmp_error_buf[0] = '\0';
    if (type == ERR_MIN || type > ERR_MAX)
	fatal_dump("cached_error_url: type out of range.");
    index = (int) (type - ERR_MIN);
    sprintf(tmp_error_buf, CACHED_ERROR_MSG_P1,
	url,
	url,
	ErrorData[index].shrt);

    if (msg) {
	sprintf(tbuf, CACHED_ERROR_MSG_P2, msg);
	strcat(tmp_error_buf, tbuf);
    }
    sprintf(tbuf, CACHED_ERROR_MSG_P3,
	ErrorData[index].lng,
	SQUID_VERSION,
	getMyHostname());
    if (!log_errors)
