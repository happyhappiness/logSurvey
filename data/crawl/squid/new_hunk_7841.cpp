}


void squid_error_entry(entry, type, msg)
     StoreEntry *entry;
     int type;
     char *msg;
{
    int index;
    if (type < ERR_MIN || type > ERR_MAX)
	fatal_dump("squid_error_entry: type out of range.");
    index = (int) (type - ERR_MIN);
    sprintf(tmp_error_buf, SQUID_ERROR_MSG_P1,
	entry->url,
	entry->url,
	ErrorData[index].shrt);
    if (msg) {
	sprintf(tbuf, SQUID_ERROR_MSG_P2, msg);
	strcat(tmp_error_buf, tbuf);
    }
    sprintf(tbuf, SQUID_ERROR_MSG_P3,
	ErrorData[index].lng,
	appname,
	version_string,
	getMyHostname());
    strcat(tmp_error_buf, tbuf);
