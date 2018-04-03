{
	struct active_request_slot *slot;
	struct slot_results results;
	char *out_data;
	char *if_header;
	struct buffer out_buffer;
	struct curl_slist *dav_headers = NULL;
	int i;

	if_header = xmalloc(strlen(lock->token) + 25);
	sprintf(if_header, "If: (<opaquelocktoken:%s>)", lock->token);
	dav_headers = curl_slist_append(dav_headers, if_header);

	out_buffer.size = 41;
	out_data = xmalloc(out_buffer.size + 1);
	i = snprintf(out_data, out_buffer.size + 1, "%s\n", sha1_to_hex(sha1));
	if (i != out_buffer.size) {
		fprintf(stderr, "Unable to initialize PUT request body\n");
		return 0;
	}
	out_buffer.posn = 0;
	out_buffer.buffer = out_data;

	slot = get_active_slot();
	slot->results = &results;
	curl_easy_setopt(slot->curl, CURLOPT_INFILE, &out_buffer);
	curl_easy_setopt(slot->curl, CURLOPT_INFILESIZE, out_buffer.size);
	curl_easy_setopt(slot->curl, CURLOPT_READFUNCTION, fread_buffer);
	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_null);
	curl_easy_setopt(slot->curl, CURLOPT_CUSTOMREQUEST, DAV_PUT);
