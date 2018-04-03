		run_active_slot(slot);
		ret = handle_curl_result(&results);
	} else {
		snprintf(curl_errorstr, sizeof(curl_errorstr),
			 "failed to start HTTP request");
		ret = HTTP_START_FAILED;
	}

