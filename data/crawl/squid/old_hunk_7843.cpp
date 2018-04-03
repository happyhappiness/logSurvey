
    *tmp_error_buf = '\0';
    if (type == ERR_MIN || type > ERR_MAX)
	fatal_dump("cached_error_url: type out of range.");
    index = (int) (type - ERR_MIN);

    sprintf(tmp_error_buf, "HTTP/1.0 %d Cache Detected Error\r\nContent-type: text/html\r\n\r\n", code);
    sprintf(tbuf, CACHED_REQUEST_ERROR_MSG,
	request,
	version_string,
	getMyHostname());
    strcat(tmp_error_buf, tbuf);
