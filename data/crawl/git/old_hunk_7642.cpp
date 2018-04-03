	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK)
			return error("Couldn't get %s for %s\n%s",
				     url, ref, curl_errorstr);
	} else {
		return error("Unable to start request");
	}

	strbuf_rtrim(&buffer);
	if (buffer.len != 40)
		return 1;
	return get_sha1_hex(buffer.buf, sha1);
}

static void cleanup(struct walker *walker)