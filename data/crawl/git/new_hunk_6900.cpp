		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			strbuf_release(&buffer);
			if (missing_target(&results))
				die("%s not found: did you run git update-server-info on the server?", refs_url);
			else
				die("%s download error - %s", refs_url, curl_errorstr);
		}
	} else {
		strbuf_release(&buffer);
		die("Unable to start HTTP request");
	}

	data = buffer.buf;