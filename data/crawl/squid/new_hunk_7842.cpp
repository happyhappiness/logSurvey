
    *tmp_error_buf = '\0';
    if (type == ERR_MIN || type > ERR_MAX)
	fatal_dump("squid_error_url: type out of range.");
    index = (int) (type - ERR_MIN);
    sprintf(tmp_error_buf, "HTTP/1.0 %d Cache Detected Error\r\nContent-type: text/html\r\n\r\n", code);
    sprintf(tbuf, SQUID_ERROR_MSG_P1,
	url,
	url,
	ErrorData[index].shrt);
    strcat(tmp_error_buf, tbuf);
    if (msg) {
	sprintf(tbuf, SQUID_ERROR_MSG_P2, msg);
	strcat(tmp_error_buf, tbuf);
    }
    sprintf(tbuf, SQUID_ERROR_MSG_P3,
	ErrorData[index].lng,
	appname,
	version_string,
	getMyHostname());
    if (!log_errors)
