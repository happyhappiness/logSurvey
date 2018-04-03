	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			free(url);
			return error("Unable to verify pack %s is available",
				     hex);
		}
	} else {
		free(url);
		return error("Unable to start request");
	}

	if (has_pack_index(sha1)) {
		free(url);
		return 0;
	}

	if (push_verbosely)
