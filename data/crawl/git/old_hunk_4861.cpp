	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, rpc_in);
	curl_easy_setopt(slot->curl, CURLOPT_FILE, rpc);

	slot->curl_result = curl_easy_perform(slot->curl);
	finish_active_slot(slot);

	if (results.curl_result != CURLE_OK) {
		err |= error("RPC failed; result=%d, HTTP code = %ld",
			results.curl_result, results.http_code);
	}

	curl_slist_free_all(headers);
	free(gzip_body);