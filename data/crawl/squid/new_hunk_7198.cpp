    if (type < ERR_MIN || type > ERR_MAX)
	fatal_dump("squid_error_request: type out of range.");
    error_index = (int) (type - ERR_MIN);
    debug(4, 1) ("%s: %s\n", ErrorData[error_index].tag, request);
    sprintf(tmp_error_buf, "HTTP/1.0 %d Cache Detected Error\r\nContent-type: text/html\r\n\r\n", code);
    sprintf(tbuf, SQUID_REQUEST_ERROR_MSG,
	request,
