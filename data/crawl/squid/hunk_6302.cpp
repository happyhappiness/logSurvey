     struct _request *r = data;
     static unsigned char buf[READ_BUF_SZ];
     int len;
-    if ((len=read(fd, buf, READ_BUF_SZ)) <= 0) {
+    if ((len = read(fd, buf, READ_BUF_SZ)) <= 0) {
 	fd_close(fd);
 	reqpersec++;
 	nrequests++;
     } else {
-	int used=0;
-	total_bytes_read+=len;
+	int used = 0;
+	total_bytes_read += len;
 	if (r->headfound < 2) {
-	    char *p,*header = NULL;
+	    char *p, *header = NULL;
 	    int oldlen = strlen(r->buf);
 	    int newlen = oldlen + len;
 	    assert(oldlen <= READ_BUF_SZ);
-	    memcpy(r->buf+oldlen, buf, len);
-	    r->buf[newlen+1]='\0';
-	    for(p=r->buf; r->headfound < 2 && used<newlen; p++,used++) {
-		switch(*p) {
+	    memcpy(r->buf + oldlen, buf, len);
+	    r->buf[newlen + 1] = '\0';
+	    for (p = r->buf; r->headfound < 2 && used < newlen; p++, used++) {
+		switch (*p) {
 		case '\n':
 		    r->headfound++;
 		    if (header) {
 			/* Decode header */
-			if (strncasecmp(header,"Content-Length:",15)==0)
-			    r->content_length = atoi(header+15);
-			if (strncasecmp(header,"X-Request-URI:",14)==0) {
+			if (strncasecmp(header, "Content-Length:", 15) == 0)
+			    r->content_length = atoi(header + 15);
+			if (strncasecmp(header, "X-Request-URI:", 14) == 0) {
 			    /* Check URI */
-			    if (strncmp(r->url, header+15, strcspn(header+15,"\r\n"))) {
+			    if (strncmp(r->url, header + 15, strcspn(header + 15, "\r\n"))) {
 				char url[8192];
-				strncpy(url, header+15, strcspn(header+15,"\r\n"));
-				url[strcspn(header+15, "\r\n")]='\n';
-				fprintf(stderr,"ERROR: Sent %s received %s\n",
-					r->url, url);
+				strncpy(url, header + 15, strcspn(header + 15, "\r\n"));
+				url[strcspn(header + 15, "\r\n")] = '\n';
+				fprintf(stderr, "ERROR: Sent %s received %s\n",
+				    r->url, url);
 			    }
 			}
-			header=NULL;
+			header = NULL;
 		    }
 		    break;
 		case '\r':
 		    break;
 		default:
-		    r->headfound=0;
+		    r->headfound = 0;
 		    if (!header)
 			header = p;
 		    break;
