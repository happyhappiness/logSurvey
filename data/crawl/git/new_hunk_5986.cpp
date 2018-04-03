{
	char *url;
	struct strbuf buffer = STRBUF_INIT;
	int ret = -1;

	url = quote_ref_url(base, ref->name);
	if (http_get_strbuf(url, &buffer, HTTP_NO_CACHE) == HTTP_OK) {
		strbuf_rtrim(&buffer);
		if (buffer.len == 40)
			ret = get_sha1_hex(buffer.buf, ref->old_sha1);
		else if (!prefixcmp(buffer.buf, "ref: ")) {
			ref->symref = xstrdup(buffer.buf + 5);
			ret = 0;
		}
	}

	strbuf_release(&buffer);