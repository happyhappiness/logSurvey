 	int ret = http_request(url, type, result, target, options);
 	if (ret != HTTP_REAUTH)
 		return ret;
+
+	/*
+	 * If we are using KEEP_ERROR, the previous request may have
+	 * put cruft into our output stream; we should clear it out before
+	 * making our next request. We only know how to do this for
+	 * the strbuf case, but that is enough to satisfy current callers.
+	 */
+	if (options & HTTP_KEEP_ERROR) {
+		switch (target) {
+		case HTTP_REQUEST_STRBUF:
+			strbuf_reset(result);
+			break;
+		default:
+			die("BUG: HTTP_KEEP_ERROR is only supported with strbufs");
+		}
+	}
 	return http_request(url, type, result, target, options);
 }
 
