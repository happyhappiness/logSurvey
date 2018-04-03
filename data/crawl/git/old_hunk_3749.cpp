		run_active_slot(slot);
		ret = handle_curl_result(&results);
	} else {
		error("Unable to start HTTP request for %s", url);
		ret = HTTP_START_FAILED;
	}

