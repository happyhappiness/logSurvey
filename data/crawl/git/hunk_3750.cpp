 	return ret;
 }
 
-int http_error(const char *url, int ret)
+void http_error(const char *url)
 {
-	/* http_request has already handled HTTP_START_FAILED. */
-	if (ret != HTTP_START_FAILED)
-		error("%s while accessing %s", curl_errorstr, url);
-
-	return ret;
+	error("%s while accessing %s", curl_errorstr, url);
 }
 
 int http_fetch_ref(const char *base, struct ref *ref)
