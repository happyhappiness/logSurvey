 	return size;
 }
 
+static int run_slot(struct active_request_slot *slot)
+{
+	int err = 0;
+	struct slot_results results;
+
+	slot->results = &results;
+	slot->curl_result = curl_easy_perform(slot->curl);
+	finish_active_slot(slot);
+
+	if (results.curl_result != CURLE_OK) {
+		err |= error("RPC failed; result=%d, HTTP code = %ld",
+			results.curl_result, results.http_code);
+	}
+
+	return err;
+}
+
+static int probe_rpc(struct rpc_state *rpc)
+{
+	struct active_request_slot *slot;
+	struct curl_slist *headers = NULL;
+	struct strbuf buf = STRBUF_INIT;
+	int err;
+
+	slot = get_active_slot();
+
+	headers = curl_slist_append(headers, rpc->hdr_content_type);
+	headers = curl_slist_append(headers, rpc->hdr_accept);
+
+	curl_easy_setopt(slot->curl, CURLOPT_NOBODY, 0);
+	curl_easy_setopt(slot->curl, CURLOPT_POST, 1);
+	curl_easy_setopt(slot->curl, CURLOPT_URL, rpc->service_url);
+	curl_easy_setopt(slot->curl, CURLOPT_ENCODING, "");
+	curl_easy_setopt(slot->curl, CURLOPT_POSTFIELDS, "0000");
+	curl_easy_setopt(slot->curl, CURLOPT_POSTFIELDSIZE, 4);
+	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, headers);
+	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_buffer);
+	curl_easy_setopt(slot->curl, CURLOPT_FILE, &buf);
+
+	err = run_slot(slot);
+
+	curl_slist_free_all(headers);
+	strbuf_release(&buf);
+	return err;
+}
+
 static int post_rpc(struct rpc_state *rpc)
 {
 	struct active_request_slot *slot;
-	struct slot_results results;
 	struct curl_slist *headers = NULL;
 	int use_gzip = rpc->gzip_request;
 	char *gzip_body = NULL;
-	int err = 0, large_request = 0;
+	int err, large_request = 0;
 
 	/* Try to load the entire request, if we can fit it into the
 	 * allocated buffer space we can use HTTP/1.0 and avoid the
