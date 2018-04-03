	err = run_one_slot(slot, results);

	if (err != HTTP_OK && err != HTTP_REAUTH) {
		error("RPC failed; result=%d, HTTP code = %ld",
		      results->curl_result, results->http_code);
	}

	return err;