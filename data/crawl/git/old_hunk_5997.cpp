	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.curl_result != CURLE_OK) {
			fclose(indexfile);
			slot->local = NULL;
			return error("Unable to get pack index %s\n%s", url,
				     curl_errorstr);
		}
	} else {
		fclose(indexfile);
		slot->local = NULL;
		return error("Unable to start request");
	}

	fclose(indexfile);
	slot->local = NULL;
