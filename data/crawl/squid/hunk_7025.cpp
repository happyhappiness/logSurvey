     snprintf(buf, BUFSIZ, "\r\n");
     strcat(msg, buf);
 
-    /* Send the HTTP request */
-    bytesWritten = write(conn, msg, strlen(msg));
-    if (bytesWritten < 0) {
-	perror("client: ERROR: write");
-	exit(1);
-    } else if (bytesWritten != strlen(msg)) {
-	fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
-	exit(1);
+    if (ping) {
+#if HAVE_SIGACTION
+	struct sigaction sa, osa;
+	if (sigaction(SIGINT, NULL, &osa) == 0 && osa.sa_handler == SIG_DFL) {
+	    sa.sa_handler = catch;
+	    sa.sa_flags = 0;
+	    sigemptyset(&sa.sa_mask);
+	    (void) sigaction(SIGINT, &sa, NULL);
+	}
+#else
+	void (*osig) ();
+	if ((osig = signal(SIGINT, catch)) != SIG_DFL)
+	    (void) signal(SIGINT, osig);
+#endif
+    }
+    loops = ping ? pcount : 1;
+    for (i = 0; loops == 0 || i < loops; i++) {
+	/* Connect to the server */
+	if ((conn = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
+	    perror("client: socket");
+	    exit(1);
+	}
+	if (client_comm_connect(conn, hostname, port, ping ? &tv1 : NULL) < 0) {
+	    if (errno == 0) {
+		fprintf(stderr, "client: ERROR: Cannot connect to %s:%d: Host unknown.\n", hostname, port);
+	    } else {
+		char tbuf[BUFSIZ];
+		sprintf(tbuf, "client: ERROR: Cannot connect to %s:%d",
+		    hostname, port);
+		perror(tbuf);
+	    }
+	    exit(1);
+	}
+	/* Send the HTTP request */
+	bytesWritten = write(conn, msg, strlen(msg));
+	if (bytesWritten < 0) {
+	    perror("client: ERROR: write");
+	    exit(1);
+	} else if (bytesWritten != strlen(msg)) {
+	    fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
+	    exit(1);
+	}
+	/* Read the data */
+	while ((len = read(conn, buf, sizeof(buf))) > 0) {
+	    if (to_stdout)
+		fwrite(buf, len, 1, stdout);
+	}
+	(void) close(conn);	/* done with socket */
+
+	if (interrupted)
+	    break;
+
+	if (ping) {
+	    struct tm *tmp;
+	    time_t t2s;
+	    long elapsed_msec;
+
+	    (void) Now(&tv2);
+	    elapsed_msec = tvSubMsec(tv1, tv2);
+	    t2s = tv2.tv_sec;
+	    tmp = localtime(&t2s);
+	    fprintf(stderr, "%d-%02d-%02d %02d:%02d:%02d [%d]: %ld.%03ld secs\n",
+		tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday,
+		tmp->tm_hour, tmp->tm_min, tmp->tm_sec, i + 1,
+		elapsed_msec / 1000, elapsed_msec % 1000);
+	    if (i == 0 || elapsed_msec < ping_min)
+		ping_min = elapsed_msec;
+	    if (i == 0 || elapsed_msec > ping_max)
+		ping_max = elapsed_msec;
+	    ping_sum += elapsed_msec;
+	    /* Delay until next "ping_int" boundary */
+	    if ((loops == 0 || i + 1 < loops) && elapsed_msec < ping_int) {
+		struct timeval tvs;
+		long msec_left = ping_int - elapsed_msec;
+
+		tvs.tv_sec = msec_left / 1000;
+		tvs.tv_usec = (msec_left % 1000) * 1000;
+		select(0, NULL, NULL, NULL, &tvs);
+	    }
+	}
     }
-    /* Read the data */
-    while ((len = read(conn, buf, sizeof(buf))) > 0) {
-	if (to_stdout)
-	    fwrite(buf, len, 1, stdout);
+
+    if (ping && i) {
+	ping_mean = ping_sum / i;
+	fprintf(stderr, "%d requests, round-trip (secs) min/avg/max = "
+	    "%ld.%03ld/%ld.%03ld/%ld.%03ld\n", i,
+	    ping_min / 1000, ping_min % 1000, ping_mean / 1000, ping_mean % 1000,
+	    ping_max / 1000, ping_max % 1000);
     }
-    (void) close(conn);		/* done with socket */
     exit(0);
     /*NOTREACHED */
     return 0;
 }
 
 static int
-client_comm_connect(int sock, char *dest_host, u_short dest_port)
+client_comm_connect(int sock, char *dest_host, u_short dest_port, struct timeval *tvp)
 {
-    const struct hostent *hp;
+    static const struct hostent *hp = NULL;
     static struct sockaddr_in to_addr;
 
     /* Set up the destination socket address for message to send to. */
-    to_addr.sin_family = AF_INET;
+    if (hp == NULL) {
+	to_addr.sin_family = AF_INET;
 
-    if ((hp = gethostbyname(dest_host)) == 0) {
-	return (-1);
+	if ((hp = gethostbyname(dest_host)) == 0) {
+	    return (-1);
+	}
+	xmemcpy(&to_addr.sin_addr, hp->h_addr, hp->h_length);
+	to_addr.sin_port = htons(dest_port);
     }
-    xmemcpy(&to_addr.sin_addr, hp->h_addr, hp->h_length);
-    to_addr.sin_port = htons(dest_port);
+    if (tvp)
+	(void) Now(tvp);
     return connect(sock, (struct sockaddr *) &to_addr, sizeof(struct sockaddr_in));
 }
+
+static int
+Now(struct timeval *tp)
+{
+#if GETTIMEOFDAY_NO_TZP
+    return gettimeofday(tp);
+#else
+    return gettimeofday(tp, NULL);
+#endif
+}				/* ARGSUSED */
+
+static void
+catch(int sig)
+{
+    interrupted = 1;
+    fprintf(stderr, "Interrupted.\n");
+}