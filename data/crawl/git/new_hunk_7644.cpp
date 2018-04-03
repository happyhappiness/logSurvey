	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			strbuf_release(&buffer);
			free(url);
			if (results.http_code == 404)
				return 0;
			else
				return error("%s", curl_errorstr);
		}
	} else {
		strbuf_release(&buffer);
		free(url);
		return error("Unable to start request");
	}
	free(url);

	data = buffer.buf;
	while (i < buffer.len) {
		switch (data[i]) {
		case 'P':
			i++;
			if (i + 52 < buffer.len &&
			    !prefixcmp(data + i, " pack-") &&
			    !prefixcmp(data + i + 46, ".pack\n")) {
				get_sha1_hex(data + i + 6, sha1);
