			sha1_to_hex(sha1));
	}

	preq = new_http_pack_request(target, repo->base);
	if (preq == NULL)
		goto abort;
	preq->lst = &repo->packs;
	preq->slot->results = &results;

	if (start_active_slot(preq->slot)) {
		run_active_slot(preq->slot);
		if (results.curl_result != CURLE_OK) {
			error("Unable to get pack file %s\n%s", preq->url,
			      curl_errorstr);
			goto abort;
		}
	} else {
		error("Unable to start request");
		goto abort;
	}

	ret = finish_http_pack_request(preq);
	release_http_pack_request(preq);
	if (ret)
		return ret;

	return 0;

abort:
	return -1;
}

static void abort_object_request(struct object_request *obj_req)
