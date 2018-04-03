			start_fetch_packed(request);

	} else if (request->state == RUN_FETCH_PACKED) {
		int fail = 1;
		if (request->curl_result != CURLE_OK) {
			fprintf(stderr, "Unable to get pack file %s\n%s",
				request->url, curl_errorstr);
		} else {
			preq = (struct http_pack_request *)request->userData;

			if (preq) {
				if (finish_http_pack_request(preq) > 0)
					fail = 0;
				release_http_pack_request(preq);
			}
		}
		if (fail)
			repo->can_update_info_refs = 0;
		release_request(request);
	}
}
