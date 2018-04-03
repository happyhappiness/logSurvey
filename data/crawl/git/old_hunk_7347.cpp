void http_cleanup(void)
{
	struct active_request_slot *slot = active_queue_head;
#ifdef USE_CURL_MULTI
	char *wait_url;
#endif

	while (slot != NULL) {
		struct active_request_slot *next = slot->next;
#ifdef USE_CURL_MULTI
		if (slot->in_use) {
			curl_easy_getinfo(slot->curl,
					  CURLINFO_EFFECTIVE_URL,
					  &wait_url);
			fprintf(stderr, "Waiting for %s\n", wait_url);
			run_active_slot(slot);
		}
#endif
		if (slot->curl != NULL)
			curl_easy_cleanup(slot->curl);
		free(slot);
		slot = next;
	}