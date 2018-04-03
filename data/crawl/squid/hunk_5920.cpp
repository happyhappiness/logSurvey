 	/* Process headers */
 	if (r->hdr_length == 0 && (end = mime_headers_end(r->reply_hdrs)) != NULL) {
 #if 0
-	    fprintf(stderr, "FOUND EOH FOR %s\n", r->url); */
+	    fprintf(stderr, "FOUND EOH FOR %s\n", r->url);
+	    */
 #endif
-	    r->hdr_length = end - r->reply_hdrs;
+		r->hdr_length = end - r->reply_hdrs;
 #if 0
- 	    fprintf(stderr, "HDR_LENGTH = %d\n", r->hdr_length);
+	    fprintf(stderr, "HDR_LENGTH = %d\n", r->hdr_length);
 #endif
 	    /* "unread" any body contents received */
 	    blen = r->hdr_offset - r->hdr_length;
