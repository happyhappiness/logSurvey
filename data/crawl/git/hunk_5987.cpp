 	refs_url = xmalloc(strlen(transport->url) + 11);
 	sprintf(refs_url, "%s/info/refs", transport->url);
 
-	slot = get_active_slot();
-	slot->results = &results;
-	curl_easy_setopt(slot->curl, CURLOPT_FILE, &buffer);
-	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_buffer);
-	curl_easy_setopt(slot->curl, CURLOPT_URL, refs_url);
-	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, NULL);
-
-	if (start_active_slot(slot)) {
-		run_active_slot(slot);
-		if (results.curl_result != CURLE_OK) {
-			strbuf_release(&buffer);
-			if (missing_target(&results))
-				die("%s not found: did you run git update-server-info on the server?", refs_url);
-			else
-				die("%s download error - %s", refs_url, curl_errorstr);
-		}
-	} else {
-		strbuf_release(&buffer);
-		die("Unable to start HTTP request");
+	http_ret = http_get_strbuf(refs_url, &buffer, HTTP_NO_CACHE);
+	switch (http_ret) {
+	case HTTP_OK:
+		break;
+	case HTTP_MISSING_TARGET:
+		die("%s not found: did you run git update-server-info on the"
+		    " server?", refs_url);
+	default:
+		http_error(refs_url, http_ret);
+		die("HTTP request failed");
 	}
 
 	data = buffer.buf;
