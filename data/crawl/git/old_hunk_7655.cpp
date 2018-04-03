	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			if (missing_target(&results)) {
				free(buffer.buffer);
				return NULL;
			} else {
				free(buffer.buffer);
				error("%s", curl_errorstr);
				return NULL;
			}
		}
	} else {
		free(buffer.buffer);
		error("Unable to start request");
		return NULL;
	}

	http_cleanup();

	data = buffer.buffer;
	start = NULL;
	mid = data;
	while (i < buffer.posn) {
		if (!start)
			start = &data[i];
		if (data[i] == '\t')
