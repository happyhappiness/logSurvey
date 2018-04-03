	refs_url = xmalloc(strlen(transport->url) + 11);
	sprintf(refs_url, "%s/info/refs", transport->url);

	http_ret = http_get_strbuf(refs_url, &buffer, HTTP_NO_CACHE);
	switch (http_ret) {
	case HTTP_OK:
		break;
	case HTTP_MISSING_TARGET:
		die("%s not found: did you run git update-server-info on the"
		    " server?", refs_url);
	default:
		http_error(refs_url, http_ret);
		die("HTTP request failed");
	}

	data = buffer.buf;
