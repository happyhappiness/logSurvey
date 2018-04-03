	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			strbuf_release(&buffer);
			if (missing_target(&results)) {
				repo->got_indices = 1;
				return 0;
			} else {
				repo->got_indices = 0;
				return error("%s", curl_errorstr);
			}
		}
	} else {
		repo->got_indices = 0;
		strbuf_release(&buffer);
		return error("Unable to start request");
	}

	data = buffer.buf;
	while (i < buffer.len) {
		switch (data[i]) {
		case 'P':
			i++;
			if (i + 52 <= buffer.len &&
			    !prefixcmp(data + i, " pack-") &&
			    !prefixcmp(data + i + 46, ".pack\n")) {
				get_sha1_hex(data + i + 6, sha1);
