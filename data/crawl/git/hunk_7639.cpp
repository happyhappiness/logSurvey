 	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
 	if (start_active_slot(slot)) {
 		run_active_slot(slot);
-		free(url);
-		if (results.curl_result != CURLE_OK)
-			return error("Couldn't get %s for %s\n%s",
-				     url, ref, curl_errorstr);
+		if (results.curl_result == CURLE_OK) {
+			strbuf_rtrim(&buffer);
+			if (buffer.len == 40)
+				ret = get_sha1_hex(buffer.buf, sha1);
+			else
+				ret = 1;
+		} else {
+			ret = error("Couldn't get %s for %s\n%s",
+				    url, ref, curl_errorstr);
+		}
 	} else {
-		free(url);
-		return error("Unable to start request");
+		ret = error("Unable to start request");
 	}
 
-	strbuf_rtrim(&buffer);
-	if (buffer.len != 40)
-		return 1;
-	return get_sha1_hex(buffer.buf, sha1);
+	strbuf_release(&buffer);
+	free(url);
+	return ret;
 }
 
 static void one_remote_object(const char *hex)
