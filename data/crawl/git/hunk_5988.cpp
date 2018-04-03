 	return strbuf_detach(&buf, NULL);
 }
 
+/* http_request() targets */
+#define HTTP_REQUEST_STRBUF	0
+#define HTTP_REQUEST_FILE	1
+
+static int http_request(const char *url, void *result, int target, int options)
+{
+	struct active_request_slot *slot;
+	struct slot_results results;
+	struct curl_slist *headers = NULL;
+	struct strbuf buf = STRBUF_INIT;
+	int ret;
+
+	slot = get_active_slot();
+	slot->results = &results;
+	curl_easy_setopt(slot->curl, CURLOPT_HTTPGET, 1);
+
+	if (result == NULL) {
+		curl_easy_setopt(slot->curl, CURLOPT_NOBODY, 1);
+	} else {
+		curl_easy_setopt(slot->curl, CURLOPT_NOBODY, 0);
+		curl_easy_setopt(slot->curl, CURLOPT_FILE, result);
+
+		if (target == HTTP_REQUEST_FILE) {
+			long posn = ftell(result);
+			curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION,
+					 fwrite);
+			if (posn > 0) {
+				strbuf_addf(&buf, "Range: bytes=%ld-", posn);
+				headers = curl_slist_append(headers, buf.buf);
+				strbuf_reset(&buf);
+			}
+			slot->local = result;
+		} else
+			curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION,
+					 fwrite_buffer);
+	}
+
+	strbuf_addstr(&buf, "Pragma:");
+	if (options & HTTP_NO_CACHE)
+		strbuf_addstr(&buf, " no-cache");
+
+	headers = curl_slist_append(headers, buf.buf);
+
+	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
+	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, headers);
+
+	if (start_active_slot(slot)) {
+		run_active_slot(slot);
+		if (results.curl_result == CURLE_OK)
+			ret = HTTP_OK;
+		else if (missing_target(&results))
+			ret = HTTP_MISSING_TARGET;
+		else
+			ret = HTTP_ERROR;
+	} else {
+		error("Unable to start HTTP request for %s", url);
+		ret = HTTP_START_FAILED;
+	}
+
+	slot->local = NULL;
+	curl_slist_free_all(headers);
+	strbuf_release(&buf);
+
+	return ret;
+}
+
+int http_get_strbuf(const char *url, struct strbuf *result, int options)
+{
+	return http_request(url, result, HTTP_REQUEST_STRBUF, options);
+}
+
+int http_get_file(const char *url, const char *filename, int options)
+{
+	int ret;
+	struct strbuf tmpfile = STRBUF_INIT;
+	FILE *result;
+
+	strbuf_addf(&tmpfile, "%s.temp", filename);
+	result = fopen(tmpfile.buf, "a");
+	if (! result) {
+		error("Unable to open local file %s", tmpfile.buf);
+		ret = HTTP_ERROR;
+		goto cleanup;
+	}
+
+	ret = http_request(url, result, HTTP_REQUEST_FILE, options);
+	fclose(result);
+
+	if ((ret == HTTP_OK) && move_temp_to_file(tmpfile.buf, filename))
+		ret = HTTP_ERROR;
+cleanup:
+	strbuf_release(&tmpfile);
+	return ret;
+}
+
+int http_error(const char *url, int ret)
+{
+	/* http_request has already handled HTTP_START_FAILED. */
+	if (ret != HTTP_START_FAILED)
+		error("%s while accessing %s\n", curl_errorstr, url);
+
+	return ret;
+}
+
 int http_fetch_ref(const char *base, struct ref *ref)
 {
 	char *url;
