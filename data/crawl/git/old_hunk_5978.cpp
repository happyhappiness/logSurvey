	char *hex = xstrdup(sha1_to_hex(sha1));
	char *filename;
	char *url;
	char tmpfile[PATH_MAX];
	long prev_posn = 0;
	char range[RANGE_HEADER_SIZE];
	struct strbuf buf = STRBUF_INIT;
	struct curl_slist *range_header = NULL;

	FILE *indexfile;
	struct active_request_slot *slot;
	struct slot_results results;

	/* Don't use the index if the pack isn't there */
	end_url_with_slash(&buf, base_url);
	strbuf_addf(&buf, "objects/pack/pack-%s.pack", hex);
	url = strbuf_detach(&buf, 0);

	slot = get_active_slot();
	slot->results = &results;
	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
	curl_easy_setopt(slot->curl, CURLOPT_NOBODY, 1);
	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			ret = error("Unable to verify pack %s is available",
				    hex);
			goto cleanup_pack;
		}
	} else {
		ret = error("Unable to start request");
		goto cleanup_pack;
	}

	if (has_pack_index(sha1)) {
		ret = 0;
		goto cleanup_pack;
	}

	if (http_is_verbose)
