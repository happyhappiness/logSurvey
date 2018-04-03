	char *url;
	struct strbuf buf = STRBUF_INIT;

	if (has_pack_index(sha1)) {
		ret = 0;
		goto cleanup;