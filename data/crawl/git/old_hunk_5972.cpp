	start_object_request(walker, obj_req);
#endif

	while (obj_req->state == ACTIVE)
		run_active_slot(obj_req->slot);

	if (obj_req->local != -1) {
		close(obj_req->local);
		obj_req->local = -1;
	}

	if (obj_req->state == ABORTED) {
		ret = error("Request for %s aborted", hex);
	} else if (obj_req->curl_result != CURLE_OK &&
		   obj_req->http_code != 416) {
		if (missing_target(obj_req))
			ret = -1; /* Be silent, it is probably in a pack. */
		else
			ret = error("%s (curl_result = %d, http_code = %ld, sha1 = %s)",
				    obj_req->errorstr, obj_req->curl_result,
				    obj_req->http_code, hex);
	} else if (obj_req->zret != Z_STREAM_END) {
		walker->corrupt_object_found++;
		ret = error("File %s (%s) corrupt", hex, obj_req->url);
	} else if (hashcmp(obj_req->sha1, obj_req->real_sha1)) {
		ret = error("File %s has bad hash", hex);
	} else if (obj_req->rename < 0) {
		ret = error("unable to write sha1 filename %s",
			    obj_req->filename);
	}

	release_object_request(obj_req);
	return ret;
}
