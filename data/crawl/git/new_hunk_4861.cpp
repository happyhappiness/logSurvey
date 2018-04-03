	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, rpc_in);
	curl_easy_setopt(slot->curl, CURLOPT_FILE, rpc);

	err = run_slot(slot);

	curl_slist_free_all(headers);
	free(gzip_body);