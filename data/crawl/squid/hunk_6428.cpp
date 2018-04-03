 	    return atoi(t);
 	}
     }
-    return 0;
+    return -1;
 }
 
+static const char *
+get_header_string_value(const char *hdr, const char *buf, const char *end)
+{
+    const char *t;
+    static char result[8192];
+    for (t = buf; t < end; t += strcspn(t, crlf), t += strspn(t, crlf)) {
+	if (strncasecmp(t, hdr, strlen(hdr)) == 0) {
+	    t += strlen(hdr);
+	    while (isspace(*t))
+		t++;
+	    strcpy(result,"");
+	    strncat(result,t,strcspn(t, crlf));
+	    return result;
+	}
+    }
+    return NULL;
+}
+
+void
+request_done(struct _r *r)
+{
+#if 0
+    fprintf(stderr, "DONE: %s, (%d+%d)\n",
+	    r->url,
+	    r->hdr_length,
+	    r->content_length);
+#endif
+    if (r->content_length != r->bytes_read)
+	fprintf(stderr, "ERROR! Short reply, expected %d bytes got %d\n",
+	    r->content_length, r->bytes_read);
+    else if (r->validsize >= 0) {
+	if (r->validsize != r->bytes_read)
+	    fprintf(stderr, "WARNING: %s Object size mismatch, expected %d got %d\n",
+		    r->url, r->validsize, r->bytes_read);
+	else if (opt_checksum && r->sum != r->validsum)
+	    fprintf(stderr, "WARNING: %s Checksum error. Expected %d got %d\n",
+		    r->url, r->validsum, r->sum);
+    }
+}
 int
-handle_read(char *buf, int len)
+handle_read(char *inbuf, int len)
 {
     struct _r *r = Requests;
     const char *end;
-    int hlen;
-    if (len < 0) {
+    const char *url;
+    static char buf[READ_BUF_SZ];
+    int hlen,blen;
+    if (len < 0 ) {
 	perror("read");
 	Requests = r->next;
+	request_done(r);
 	free(r);
 	noutstanding--;
+	if (trace_fd >= 0)
+	    write(trace_fd,"\n[CLOSED]\n",10);
 	return -1;
     }
+    total_bytes_read += len;
+    xmemcpy(buf,inbuf,len);
     if (len == 0) {
-	fprintf(stderr, "DONE: %s, server closed socket, read %d bytes\n", r->url, r->bytes_read);
+	fprintf(stderr, "WARNING: %s, server closed socket after %d+%d bytes\n", r->url, r->hdr_offset, r->bytes_read);
+	/* XXX, If no data was received and it isn't the first request on this
+	 * connection then the request should be restarted rather than aborted
+	 * but this is a simple test program an not a full blown HTTP client.
+	 */
+	request_done(r);
 	Requests = r->next;
 	free(r);
 	noutstanding--;
 	return -1;
     }
-    if (r->hdr_length == 0) {
-	hlen = min(len, REPLY_HDR_SZ - r->hdr_length);
-	strncpy(r->reply_hdrs + r->hdr_length, buf, hlen);
-	r->hdr_offset += hlen;
-	*(r->reply_hdrs + REPLY_HDR_SZ - 1) = '\0';
-    }
-    if (r->hdr_length == 0 && (end = mime_headers_end(r->reply_hdrs)) != NULL) {
-	fprintf(stderr, "FOUND EOH FOR %s\n", r->url);
-	r->hdr_length = end - r->reply_hdrs;
-	fprintf(stderr, "HDR_LENGTH = %d\n", r->hdr_length);
-	r->content_length = get_header_int_value("content-length:", r->reply_hdrs, end);
-	fprintf(stderr, "CONTENT_LENGTH = %d\n", r->content_length);
-    }
-    if (r->content_length && r->hdr_length) {
-	int bytes_left = r->content_length + r->hdr_length - r->bytes_read;
-	int bytes_used = len > bytes_left ? bytes_left : len;
-	r->bytes_read += bytes_used;
-	len -= bytes_used;
-	if (r->bytes_read == r->content_length + r->hdr_length) {
-	    fprintf(stderr, "DONE: %s, (%d == %d+%d)\n",
-		r->url,
-		r->bytes_read,
-		r->hdr_length,
-		r->content_length);
-	    Requests = r->next;
-	    free(r);
-	    noutstanding--;
-	} else {
-	    assert(r->bytes_read < r->content_length + r->hdr_length);
+    if (trace_fd > 0)
+	write(trace_fd, buf, len);
+    while (len > 0) {
+	/* Build headers */
+	if (r->hdr_length == 0) {
+	    hlen = min(len, REPLY_HDR_SZ - r->hdr_offset - 1);
+	    xmemcpy(r->reply_hdrs + r->hdr_offset, buf, hlen);
+	    r->hdr_offset += hlen;
+	    r->reply_hdrs[r->hdr_offset] = '\0';
+	    len -= hlen;
+	    /* Save any remaining read data */
+	    xmemmove(buf, buf + hlen, len);
+	}
+	/* Process headers */
+	if (r->hdr_length == 0 && (end = mime_headers_end(r->reply_hdrs)) != NULL) {
+#if 0
+	    fprintf(stderr, "FOUND EOH FOR %s\n", r->url); */
+#endif
+	    r->hdr_length = end - r->reply_hdrs;
+#if 0
+ 	    fprintf(stderr, "HDR_LENGTH = %d\n", r->hdr_length);
+#endif
+	    /* "unread" any body contents received */
+	    blen = r->hdr_offset - r->hdr_length;
+	    assert(blen >= 0);
+	    if (blen > 0) {
+		xmemmove(buf + blen, buf, len);
+		xmemcpy(buf, r->reply_hdrs + r->hdr_length, blen);
+		len += blen;
+	    }
+	    r->reply_hdrs[r->hdr_length]='\0'; /* Null terminate headers */
+	    /* Parse headers */
+	    r->content_length = get_header_int_value("content-length:", r->reply_hdrs, end);
+/*	    fprintf(stderr, "CONTENT_LENGTH = %d\n", r->content_length); */
+	    url = get_header_string_value("X-Request-URI:", r->reply_hdrs, end);
+	    if (url != NULL && strcmp(r->url, url) != 0)
+		fprintf(stderr, "WARNING: %s got reply %s\n", r->url, url);
+#if XREQUESTURI || 0
+	    fprintf(stderr, "LOCATION = %s\n", get_header_string_value("X-Request-URI:", r->reply_hdrs, end));  
+#endif
+	}
+	if ( !(len==0 || r->hdr_length > 0) ) {
+	    fprintf(stderr, "ERROR!!!\n");
+	    assert((len==0 || r->hdr_length > 0));
 	}
-	if (len) {
-	    assert(bytes_used > 0);
+	/* Process body */
+	if (r->hdr_length != 0) {
+	    int i;
+	    int bytes_left, bytes_used;
+	    if (r->content_length >= 0) {
+		bytes_left = r->content_length - r->bytes_read;
+		assert(bytes_left >= 0);
+	    	bytes_used = len < bytes_left ? len : bytes_left;
+	    } else {
+		bytes_left = len + 1; /* Unknown end... */
+		bytes_used = len;
+	    }
+	    if (opt_checksum) {
+		for(i=0; i<bytes_used; i++)
+		    r->sum += (int)buf[i] & 0xFF;
+	    }
+	    r->bytes_read += bytes_used;
+	    len -= bytes_used;
+	    if (bytes_left == bytes_used) {
+		request_done(r);
+		Requests = r->next;
+		free(r);
+		noutstanding--;
+		r = Requests;
+	    } else {
+		assert(r->bytes_read < r->content_length);
+	    }
 	    xmemmove(buf, buf + bytes_used, len);
-	    return handle_read(buf, len);
 	}
     }
     return 0;
