static int remote_exists(const char *path)
{
	char *url = xmalloc(strlen(repo->url) + strlen(path) + 1);
	struct active_request_slot *slot;
	struct slot_results results;
	int ret = -1;

	sprintf(url, "%s%s", repo->url, path);

	slot = get_active_slot();
	slot->results = &results;
	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
	curl_easy_setopt(slot->curl, CURLOPT_NOBODY, 1);

	if (start_active_slot(slot)) {
		run_active_slot(slot);
		if (results.http_code == 404)
			ret = 0;
		else if (results.curl_result == CURLE_OK)
			ret = 1;
		else
			fprintf(stderr, "HEAD HTTP error %ld\n", results.http_code);
	} else {
		fprintf(stderr, "Unable to start HEAD request\n");
	}

	free(url);
	return ret;
}