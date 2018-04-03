 	free_refs(refs);
 }
 
+struct rpc_state {
+	const char *service_name;
+	const char **argv;
+	char *service_url;
+	char *hdr_content_type;
+	char *hdr_accept;
+	char *buf;
+	size_t alloc;
+	size_t len;
+	size_t pos;
+	int in;
+	int out;
+	struct strbuf result;
+};
+
+static size_t rpc_out(void *ptr, size_t eltsize,
+		size_t nmemb, void *buffer_)
+{
+	size_t max = eltsize * nmemb;
+	struct rpc_state *rpc = buffer_;
+	size_t avail = rpc->len - rpc->pos;
+
+	if (!avail) {
+		avail = packet_read_line(rpc->out, rpc->buf, rpc->alloc);
+		if (!avail)
+			return 0;
+		rpc->pos = 0;
+		rpc->len = avail;
+	}
+
+	if (max < avail);
+		avail = max;
+	memcpy(ptr, rpc->buf + rpc->pos, avail);
+	rpc->pos += avail;
+	return avail;
+}
+
+static size_t rpc_in(const void *ptr, size_t eltsize,
+		size_t nmemb, void *buffer_)
+{
+	size_t size = eltsize * nmemb;
+	struct rpc_state *rpc = buffer_;
+	write_or_die(rpc->in, ptr, size);
+	return size;
+}
+
+static int post_rpc(struct rpc_state *rpc)
+{
+	struct active_request_slot *slot;
+	struct slot_results results;
+	struct curl_slist *headers = NULL;
+	int err = 0, large_request = 0;
+
+	/* Try to load the entire request, if we can fit it into the
+	 * allocated buffer space we can use HTTP/1.0 and avoid the
+	 * chunked encoding mess.
+	 */
+	while (1) {
+		size_t left = rpc->alloc - rpc->len;
+		char *buf = rpc->buf + rpc->len;
+		int n;
+
+		if (left < LARGE_PACKET_MAX) {
+			large_request = 1;
+			break;
+		}
+
+		n = packet_read_line(rpc->out, buf, left);
+		if (!n)
+			break;
+		rpc->len += n;
+	}
+
+	slot = get_active_slot();
+	slot->results = &results;
+
+	curl_easy_setopt(slot->curl, CURLOPT_POST, 1);
+	curl_easy_setopt(slot->curl, CURLOPT_NOBODY, 0);
+	curl_easy_setopt(slot->curl, CURLOPT_URL, rpc->service_url);
+
+	headers = curl_slist_append(headers, rpc->hdr_content_type);
+	headers = curl_slist_append(headers, rpc->hdr_accept);
+
+	if (large_request) {
+		/* The request body is large and the size cannot be predicted.
+		 * We must use chunked encoding to send it.
+		 */
+		headers = curl_slist_append(headers, "Expect: 100-continue");
+		headers = curl_slist_append(headers, "Transfer-Encoding: chunked");
+		curl_easy_setopt(slot->curl, CURLOPT_READFUNCTION, rpc_out);
+		curl_easy_setopt(slot->curl, CURLOPT_INFILE, rpc);
+		if (options.verbosity > 1) {
+			fprintf(stderr, "POST %s (chunked)\n", rpc->service_name);
+			fflush(stderr);
+		}
+
+	} else {
+		/* We know the complete request size in advance, use the
+		 * more normal Content-Length approach.
+		 */
+		curl_easy_setopt(slot->curl, CURLOPT_POSTFIELDS, rpc->buf);
+		curl_easy_setopt(slot->curl, CURLOPT_POSTFIELDSIZE, rpc->len);
+		if (options.verbosity > 1) {
+			fprintf(stderr, "POST %s (%lu bytes)\n",
+				rpc->service_name, (unsigned long)rpc->len);
+			fflush(stderr);
+		}
+	}
+
+	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, headers);
+	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, rpc_in);
+	curl_easy_setopt(slot->curl, CURLOPT_FILE, rpc);
+
+	slot->curl_result = curl_easy_perform(slot->curl);
+	finish_active_slot(slot);
+
+	if (results.curl_result != CURLE_OK) {
+		err |= error("RPC failed; result=%d, HTTP code = %ld",
+			results.curl_result, results.http_code);
+	}
+
+	curl_slist_free_all(headers);
+	return err;
+}
+
+static int rpc_service(struct rpc_state *rpc, struct discovery *heads)
+{
+	const char *svc = rpc->service_name;
+	struct strbuf buf = STRBUF_INIT;
+	struct child_process client;
+	int err = 0;
+
+	init_walker();
+	memset(&client, 0, sizeof(client));
+	client.in = -1;
+	client.out = -1;
+	client.git_cmd = 1;
+	client.argv = rpc->argv;
+	if (start_command(&client))
+		exit(1);
+	if (heads)
+		write_or_die(client.in, heads->buf, heads->len);
+
+	rpc->alloc = http_post_buffer;
+	rpc->buf = xmalloc(rpc->alloc);
+	rpc->in = client.in;
+	rpc->out = client.out;
+	strbuf_init(&rpc->result, 0);
+
+	strbuf_addf(&buf, "%s/%s", url, svc);
+	rpc->service_url = strbuf_detach(&buf, NULL);
+
+	strbuf_addf(&buf, "Content-Type: application/x-%s-request", svc);
+	rpc->hdr_content_type = strbuf_detach(&buf, NULL);
+
+	strbuf_addf(&buf, "Accept: application/x-%s-response", svc);
+	rpc->hdr_accept = strbuf_detach(&buf, NULL);
+
+	while (!err) {
+		int n = packet_read_line(rpc->out, rpc->buf, rpc->alloc);
+		if (!n)
+			break;
+		rpc->pos = 0;
+		rpc->len = n;
+		err |= post_rpc(rpc);
+	}
+	strbuf_read(&rpc->result, client.out, 0);
+
+	close(client.in);
+	close(client.out);
+	client.in = -1;
+	client.out = -1;
+
+	err |= finish_command(&client);
+	free(rpc->service_url);
+	free(rpc->hdr_content_type);
+	free(rpc->hdr_accept);
+	free(rpc->buf);
+	strbuf_release(&buf);
+	return err;
+}
+
 static int fetch_dumb(int nr_heads, struct ref **to_fetch)
 {
 	char **targets = xmalloc(nr_heads * sizeof(char*));
