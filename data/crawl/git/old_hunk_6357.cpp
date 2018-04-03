		if (request->curl_result != CURLE_OK) {
			fprintf(stderr, "Unable to get pack file %s\n%s",
				request->url, curl_errorstr);
			remote->can_update_info_refs = 0;
		} else {
			off_t pack_size = ftell(request->local_stream);

