		req->localfile = -1;
	}

	if (obj_req->state == ABORTED) {
		ret = error("Request for %s aborted", hex);
	} else if (req->curl_result != CURLE_OK &&
