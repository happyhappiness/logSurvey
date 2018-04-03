 icmpOpen(void)
 {
 #if USE_ICMP
-    struct sockaddr_in S;
-    int namelen = sizeof(struct sockaddr_in);
-    pid_t pid;
-    int child_sock;
-    icmp_sock = comm_open(SOCK_DGRAM,
-	0,
-	local_addr,
-	0,
-	COMM_NONBLOCKING,
-	"Pinger Socket");
-    if (icmp_sock < 0) {
-	debug(50, 0) ("icmpOpen: icmp_sock: %s\n", xstrerror());
-	return;
-    }
-    child_sock = comm_open(SOCK_DGRAM,
-	0,
-	local_addr,
-	0,
-	0,
-	"ICMP Socket");
-    if (child_sock < 0) {
-	debug(50, 0) ("icmpOpen: child_sock: %s\n", xstrerror());
-	return;
-    }
-    getsockname(icmp_sock, (struct sockaddr *) &S, &namelen);
-    if (comm_connect_addr(child_sock, &S) != COMM_OK)
-	fatal(xstrerror());
-    getsockname(child_sock, (struct sockaddr *) &S, &namelen);
-    if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
-	fatal(xstrerror());
-    /* flush or else we get dup data if unbuffered_logs is set */
-    logsFlush();
-    if ((pid = fork()) < 0) {
-	debug(50, 0) ("icmpOpen: fork: %s\n", xstrerror());
-	comm_close(icmp_sock);
-	comm_close(child_sock);
+    char *args[2];
+    int x;
+    int rfd;
+    int wfd;
+    args[0] = "(pinger)";
+    args[1] = NULL;
+    x = ipcCreate(IPC_UDP_SOCKET,
+	Config.Program.pinger,
+	args,
+	"Pinger Socket",
+	&rfd,
+	&wfd);
+    if (x < 0)
 	return;
-    }
-    if (pid == 0) {		/* child */
-	int tmp_s;
-	char *x = xcalloc((tmp_s = strlen(Config.debugOptions) + 32), 1);
-	snprintf(x, tmp_s, "SQUID_DEBUG=%s", Config.debugOptions);
-	putenv(x);
-	comm_close(icmp_sock);
-	dup2(child_sock, 0);
-	dup2(child_sock, 1);
-	comm_close(child_sock);
-	dup2(fileno(debug_log), 2);
-	fclose(debug_log);
-	enter_suid();
-	execlp(Config.Program.pinger, "(pinger)", NULL);
-	debug(50, 0) ("icmpOpen: %s: %s\n", Config.Program.pinger, xstrerror());
-	_exit(1);
-    }
-    comm_close(child_sock);
+    assert(rfd == wfd);
+    icmp_sock = rfd;
     commSetSelect(icmp_sock, COMM_SELECT_READ, icmpRecv, NULL, 0);
     commSetTimeout(icmp_sock, -1, NULL, NULL);
     debug(29, 0) ("Pinger socket opened on FD %d\n", icmp_sock);
