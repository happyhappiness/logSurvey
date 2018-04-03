	snprintf(url, BUFSIZ, "cache_object://%s/%s", hostname, t);
	xfree(t);
    }
    snprintf(msg, BUFSIZ, "%s %s HTTP/1.0\r\n", method, url);
    if (reload) {
	snprintf(buf, BUFSIZ, "Pragma: no-cache\r\n");
	strcat(msg, buf);
    }
    if (opt_noaccept == 0) {
	snprintf(buf, BUFSIZ, "Accept: */*\r\n");
	strcat(msg, buf);
