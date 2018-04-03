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

	if (walker->get_verbosely)
