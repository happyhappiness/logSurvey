     static int pconn_fd = -1;
     static char buf[8192];
     struct timeval to;
+    struct timeval now,last,start;
     fd_set R;
     struct _r *r;
     struct _r *nextr;
     int x;
     int timeouts;
+    int nrequests = 0, rrequests = 0, reqpersec = 0;
+
+    gettimeofday(&start, NULL);
+    last = start;
+
+    pconn_fd = open_http_socket();
+    if (pconn_fd < 0) {
+	perror("socket");
+	exit(1);
+    }
     while (!done_reading_urls || noutstanding) {
-	if (timeouts == 20) {
-	    close(pconn_fd);
-	    pconn_fd = -1;
-	    r = Requests;
-	    Requests = Requests->next;
-	    free(r);
-	    noutstanding--;
+	if (!opt_reopen && pconn_fd < 0) {
+	    fprintf(stderr,"TERMINATED: Connection closed\n");
+	    break;
 	}
-	if (pconn_fd < 0) {
+	if (pconn_fd<0) {
 	    pconn_fd = open_http_socket();
 	    if (pconn_fd < 0) {
 		perror("socket");
 		exit(1);
 	    }
 	    nextr = Requests;
 	    Requests = NULL;
+	    noutstanding=0;
 	    while ((r = nextr) != NULL) {
 		nextr = r->next;
-		send_request(pconn_fd, r->url);
+		if (send_request(pconn_fd, r->url) != 0) {
+		    close(pconn_fd);
+		    pconn_fd=-1;
+		    nextr = r;
+		    for (r = Requests; r!=NULL && r->next; r=r->next);
+		    if (r != NULL)
+			r->next = nextr;
+		    else
+			Requests = nextr;
+		    break;
+		}
 		free(r);
-		noutstanding--;
 	    }
 	    timeouts = 0;
+	    if (pconn_fd <0)
+		continue;
 	}
-	if (noutstanding < 10 && !done_reading_urls) {
+	if (timeouts == 200) {
+	    close(pconn_fd);
+	    pconn_fd = -1;
+	    r = Requests;
+	    Requests = Requests->next;
+	    fprintf(stderr, "ABORT %s\n", Requests->url);
+	    free(r);
+	    noutstanding--;
+	}
+	if (pconn_fd>=0 && noutstanding < max_outstanding && !done_reading_urls) {
 	    char *t;
 	    if (fgets(buf, 8191, stdin) == NULL) {
-		printf("Done Reading URLS\n");
+		fprintf(stderr, "Done Reading URLS\n");
 		done_reading_urls = 1;
-		break;
+		continue;
 	    }
+	    rrequests++;
 	    if ((t = strchr(buf, '\n')))
 		*t = '\0';
-	    send_request(pconn_fd, buf);
+	    if (send_request(pconn_fd, buf) != 0) {
+		close(pconn_fd);
+		pconn_fd=-1;
+		continue;
+	    }
+	    nrequests++;
+	    reqpersec++;
 	    timeouts = 0;
 	}
 	FD_ZERO(&R);
