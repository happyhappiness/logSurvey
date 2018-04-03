 reply_done(int fd, void *data)
 {
     struct _request *r = data;
-    if (opt_range)
-	; /* skip size checks for now */
+    if (opt_range);		/* skip size checks for now */
     else if (r->bodysize != r->content_length && r->content_length >= 0)
-	fprintf(stderr,"ERROR: %s got %d of %d bytes\n",
-		r->url, r->bodysize, r->content_length);
+	fprintf(stderr, "ERROR: %s got %d of %d bytes\n",
+	    r->url, r->bodysize, r->content_length);
     else if (r->validsize >= 0) {
 	if (r->validsize != r->bodysize)
-	    fprintf(stderr,"WARNING: %s size mismatch wanted %d bytes got %d\n",
-		    r->url, r->validsize, r->bodysize);
+	    fprintf(stderr, "WARNING: %s size mismatch wanted %d bytes got %d\n",
+		r->url, r->validsize, r->bodysize);
 	else if (opt_checksum && r->validsum != r->sum)
-	    fprintf(stderr,"WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
-		    r->url, r->validsum, r->sum);
+	    fprintf(stderr, "WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
+		r->url, r->validsum, r->sum);
     }
     if (trace_file) {
-	fprintf(trace_file,"%s %s %s %d 0x%lx\n",
-		r->method, r->url, r->requestbodyfile, r->bodysize, r->sum);
+	fprintf(trace_file, "%s %s %s %d 0x%lx\n",
+	    r->method, r->url, r->requestbodyfile, r->bodysize, r->sum);
     }
     free(r);
 }
 
 struct _request *
 request(char *urlin)
 {
-    int s=-1,f=-1;
+    int s = -1, f = -1;
     char buf[4096];
     char msg[8192];
     char *method, *url, *file, *size, *checksum;
     char urlbuf[8192];
-    int len,len2;
+    int len, len2;
     time_t w;
     struct stat st;
     struct sockaddr_in S;
