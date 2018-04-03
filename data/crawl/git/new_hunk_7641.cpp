	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			if (missing_target(&results)) {
				repo->got_indices = 1;
				goto cleanup;
			} else {
				repo->got_indices = 0;
				ret = error("%s", curl_errorstr);
				goto cleanup;
			}
		}
	} else {
		repo->got_indices = 0;
		ret = error("Unable to start request");
		goto cleanup;
	}

	data = buffer.buf;
