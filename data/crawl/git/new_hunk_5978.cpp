	char *hex = xstrdup(sha1_to_hex(sha1));
	char *filename;
	char *url;
	struct strbuf buf = STRBUF_INIT;

	/* Don't use the index if the pack isn't there */
	end_url_with_slash(&buf, base_url);
	strbuf_addf(&buf, "objects/pack/pack-%s.pack", hex);
	url = strbuf_detach(&buf, 0);

	if (http_get_strbuf(url, NULL, 0)) {
		ret = error("Unable to verify pack %s is available",
			    hex);
		goto cleanup;
	}

	if (has_pack_index(sha1)) {
		ret = 0;
		goto cleanup;
	}

	if (http_is_verbose)
