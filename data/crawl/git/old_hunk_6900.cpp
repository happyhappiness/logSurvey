		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			strbuf_release(&buffer);
			if (missing_target(&results)) {
				return NULL;
			} else {
				error("%s", curl_errorstr);
				return NULL;
			}
		}
	} else {
		strbuf_release(&buffer);
		error("Unable to start request");
		return NULL;
	}

	data = buffer.buf;