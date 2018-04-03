
	if (start_active_slot(slot)) {
		run_active_slot(slot);
		strbuf_release(&out_buffer.buf);
		free(if_header);
		if (results.curl_result != CURLE_OK) {
			fprintf(stderr,
