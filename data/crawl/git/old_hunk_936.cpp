		die("unable to access '%s': %s", url.buf, curl_errorstr);
	}

	last= xcalloc(1, sizeof(*last_discovery));
	last->service = service;
	last->buf_alloc = strbuf_detach(&buffer, &last->len);
