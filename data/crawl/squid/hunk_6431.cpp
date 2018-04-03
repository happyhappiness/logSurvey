 sig_intr(int sig)
 {
     fd_close(0);
+    nfds++;
     printf("\rWaiting for open connections to finish...\n");
     signal(sig, SIG_DFL);
 }
 
 void
 read_reply(int fd, void *data)
 {
-    static char buf[READ_BUF_SZ];
-    if (read(fd, buf, READ_BUF_SZ) <= 0) {
+    struct _request *r = data;
+    static unsigned char buf[READ_BUF_SZ];
+    int len;
+    char *p;
+    if ((len=read(fd, buf, READ_BUF_SZ)) <= 0) {
 	fd_close(fd);
 	reqpersec++;
 	nrequests++;
+    } else {
+	int used=0;
+	total_bytes_read+=len;
+	if (r->headfound < 2) {
+	    char *p,*header = NULL;
+	    int oldlen = strlen(r->buf);
+	    int newlen = oldlen + len;
+	    assert(oldlen <= READ_BUF_SZ);
+	    memcpy(r->buf+oldlen, buf, len);
+	    r->buf[newlen+1]='\0';
+	    for(p=r->buf; r->headfound < 2 && used<newlen; p++,used++) {
+		switch(*p) {
+		case '\n':
+		    r->headfound++;
+		    if (header) {
+			/* Decode header */
+			if (strncasecmp(header,"Content-Length:",15)==0)
+			    r->content_length = atoi(header+15);
+			if (strncasecmp(header,"X-Request-URI:",14)==0) {
+			    /* Check URI */
+			    if (strncmp(r->url, header+15, strcspn(header+15,"\r\n"))) {
+				char url[8192];
+				strncpy(url, header+15, strcspn(header+15,"\r\n"));
+				url[strcspn(header+15, "\r\n")]='\n';
+				fprintf(stderr,"ERROR: Sent %s received %s\n",
+					r->url, url);
+			    }
+			}
+			header=NULL;
+		    }
+		    break;
+		case '\r':
+		    break;
+		default:
+		    r->headfound=0;
+		    if (!header)
+			header = p;
+		    break;
+		}
+	    }
+	    if (header) {
+		memmove(r->buf, header, newlen - (header - r->buf) + 1);
+	    }
+	}
+	r->bodysize+=len-used;
+	if (opt_checksum) {
+	    for (; used<len ; used++) {
+		r->sum += buf[used];
+	    }
+	}
     }
 }
 
-int
-request(url)
-     char *url;
+void
+reply_done(int fd, void *data)
 {
-    int s;
+    struct _request *r = data;
+    if (r->bodysize != r->content_length)
+	fprintf(stderr,"ERROR: %s expected %d bytes got %d\n",
+		r->url, r->content_length, r->bodysize);
+    else if (r->validsize >= 0) {
+	if (r->validsize != r->bodysize)
+	    fprintf(stderr,"WARNING: %s size mismatch wanted %d bytes got %d\n",
+		    r->url, r->validsize, r->bodysize);
+	else if (opt_checksum && r->validsum != r->sum)
+	    fprintf(stderr,"WARNING: %s invalid checksum wanted %d got %d\n",
+		    r->url, r->validsum, r->sum);
+    } else if (opt_checksum) {
+	fprintf(stderr,"DONE: %s checksum %d size %d\n",
+		r->url, r->sum, r->bodysize);
+    }
+    free(r);
+}
+
+struct _request *
+request(char *urlin)
+{
+    int s=-1,f=-1;
     char buf[4096];
-    int len;
+    char msg[8192];
+    char *method, *url, *file, *size, *checksum;
+    char urlbuf[8192];
+    int len,len2;
     time_t w;
+    struct stat st;
     struct sockaddr_in S;
+    struct _request *r;
     if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
 	perror("socket");
-	return -1;
+	return NULL;
     }
     memset(&S, '\0', sizeof(struct sockaddr_in));
     S.sin_family = AF_INET;
