 {
 	char *url;
 	struct strbuf buffer = STRBUF_INIT;
-	struct active_request_slot *slot;
-	struct slot_results results;
-	int ret;
+	int ret = -1;
 
 	url = quote_ref_url(base, ref->name);
-	slot = get_active_slot();
-	slot->results = &results;
-	curl_easy_setopt(slot->curl, CURLOPT_FILE, &buffer);
-	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_buffer);
-	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, NULL);
-	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
-	if (start_active_slot(slot)) {
-		run_active_slot(slot);
-		if (results.curl_result == CURLE_OK) {
-			strbuf_rtrim(&buffer);
-			if (buffer.len == 40)
-				ret = get_sha1_hex(buffer.buf, ref->old_sha1);
-			else if (!prefixcmp(buffer.buf, "ref: ")) {
-				ref->symref = xstrdup(buffer.buf + 5);
-				ret = 0;
-			} else
-				ret = 1;
-		} else {
-			ret = error("Couldn't get %s for %s\n%s",
-				    url, ref->name, curl_errorstr);
+	if (http_get_strbuf(url, &buffer, HTTP_NO_CACHE) == HTTP_OK) {
+		strbuf_rtrim(&buffer);
+		if (buffer.len == 40)
+			ret = get_sha1_hex(buffer.buf, ref->old_sha1);
+		else if (!prefixcmp(buffer.buf, "ref: ")) {
+			ref->symref = xstrdup(buffer.buf + 5);
+			ret = 0;
 		}
-	} else {
-		ret = error("Unable to start request");
 	}
 
 	strbuf_release(&buffer);