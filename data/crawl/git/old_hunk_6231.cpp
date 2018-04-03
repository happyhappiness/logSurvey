	if (push_verbosely)
		fprintf(stderr, "Getting pack list\n");

	url = xmalloc(strlen(remote->url) + 20);
	sprintf(url, "%sobjects/info/packs", remote->url);

	slot = get_active_slot();
	slot->results = &results;
