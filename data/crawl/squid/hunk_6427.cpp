 }
 
 int
-send_request(int fd, const char *url)
+send_request(int fd, const char *data)
 {
-    char buf[4096];
+    char msg[4096],buf[4096];
     int len;
     time_t w;
     struct _r *r;
     struct _r **R;
-    buf[0] = '\0';
-    strcat(buf, "GET ");
-    strcat(buf, url);
-    strcat(buf, " HTTP/1.0\r\n");
-    strcat(buf, "Accept: */*\r\n");
-    strcat(buf, "Proxy-Connection: Keep-Alive\r\n");
+    char *method, *url, *file, *size, *checksum;
+    char *tmp = strdup(data);
+    struct stat st;
+    int file_fd = -1;
+    method=strtok(tmp, " ");
+    url=strtok(NULL, " ");
+    file=strtok(NULL, " ");
+    size=strtok(NULL, " ");
+    checksum=strtok(NULL, " ");
+    if (!url) {
+      url=method;
+      method="GET";
+    }
+    if (file && strcmp(file,"-")==0)
+	file=NULL;
+    if (size && strcmp(size,"-")==0)
+	size=NULL;
+    if (checksum && strcmp(checksum,"-")==0)
+	checksum=NULL;
+    msg[0] = '\0';
+    sprintf(buf, "%s %s HTTP/1.0\r\n", method, url);
+    strcat(msg,buf);
+    strcat(msg, "Accept: */*\r\n");
+    strcat(msg, "Proxy-Connection: Keep-Alive\r\n");
     if (opt_ims && (lrand48() & 0x03) == 0) {
 	w = time(NULL) - (lrand48() & 0x3FFFF);
-	strcat(buf, "If-Modified-Since: ");
-	strcat(buf, mkrfc850(&w));
-	strcat(buf, "\r\n");
+	sprintf(buf, "If-Modified-Since: %s\r\n", mkrfc850(&w));
+	strcat(msg, buf);
     }
-    strcat(buf, "\r\n");
-    len = strlen(buf);
-    if (write(fd, buf, len) < 0) {
+    if (file) {
+	if ( (file_fd = open(file,O_RDONLY)) < 0) {
+	    perror("open");
+	    return -1;
+	}
+	if ( fstat(file_fd, &st) ) {
+	    perror("fstat");
+	    close(file_fd);
+	    return -1;
+	}
+	sprintf(buf, "Content-length: %d\r\n", st.st_size);
+	strcat(msg, buf);
+    }
+    strcat(msg, "\r\n");
+    len = strlen(msg);
+    if (write(fd, msg, len) < 0) {
 	close(fd);
-	perror("write");
+	perror("request write");
+	close(file_fd);
 	return -1;
     }
+    if (file) {
+	while((len=read(file_fd, buf, sizeof buf)) > 0) {
+	    if (write(fd, buf, len) < 0) {
+		close(fd);
+		perror("body write");
+		close(file_fd);
+		return -1;
+	    }
+	}
+	if (len < 0) {
+	    perror("file read");
+	    close(file_fd);
+	    return -1;
+	}
+	close(file_fd);
+    }
     r = calloc(1, sizeof(struct _r));
-    r->url = strdup(url);
+    strcpy(r->url, url);
+    if (size)
+	r->validsize = atoi(size);
+    else
+	r->validsize = -1;
+    if (checksum)
+	r->validsum = atoi(checksum);
     for (R = &Requests; *R; R = &(*R)->next);
     *R = r;
-    fprintf(stderr, "REQUESTED %s\n", url);
+/*    fprintf(stderr, "REQUESTED %s\n", url); */
     noutstanding++;
     return 0;
 }
