		die("unable to access '%s': %s", url.buf, curl_errorstr);
	}

	if (options.verbosity && !starts_with(refs_url.buf, url.buf))
		warning(_("redirecting to %s"), url.buf);

	last= xcalloc(1, sizeof(*last_discovery));
	last->service = service;
	last->buf_alloc = strbuf_detach(&buffer, &last->len);
