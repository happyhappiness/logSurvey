 		xmemcpy(buf, r->reply_hdrs + r->hdr_length, blen);
 		len += blen;
 	    }
-	    r->reply_hdrs[r->hdr_length]='\0'; /* Null terminate headers */
+	    r->reply_hdrs[r->hdr_length] = '\0';	/* Null terminate headers */
 	    /* Parse headers */
 	    r->content_length = get_header_int_value("content-length:", r->reply_hdrs, end);
-/*	    fprintf(stderr, "CONTENT_LENGTH = %d\n", r->content_length); */
+/*          fprintf(stderr, "CONTENT_LENGTH = %d\n", r->content_length); */
 	    url = get_header_string_value("X-Request-URI:", r->reply_hdrs, end);
 	    if (url != NULL && strcmp(r->url, url) != 0)
 		fprintf(stderr, "WARNING: %s got reply %s\n", r->url, url);
 #if XREQUESTURI || 0
-	    fprintf(stderr, "LOCATION = %s\n", get_header_string_value("X-Request-URI:", r->reply_hdrs, end));  
+	    fprintf(stderr, "LOCATION = %s\n", get_header_string_value("X-Request-URI:", r->reply_hdrs, end));
 #endif
 	}
-	if ( !(len==0 || r->hdr_length > 0) ) {
+	if (!(len == 0 || r->hdr_length > 0)) {
 	    fprintf(stderr, "ERROR!!!\n");
-	    assert((len==0 || r->hdr_length > 0));
+	    assert((len == 0 || r->hdr_length > 0));
 	}
 	/* Process body */
 	if (r->hdr_length != 0) {
