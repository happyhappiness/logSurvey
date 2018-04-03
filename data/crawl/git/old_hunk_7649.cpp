
	if (start_active_slot(slot)) {
		run_active_slot(slot);
		free(out_data);
		free(if_header);
		if (results.curl_result != CURLE_OK) {
			fprintf(stderr,
