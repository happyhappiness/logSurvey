     len += ulen + 1;
     icmpSendEcho(to, S_ICMP_ICP, payload, len);
     put_free_8k_page(payload);
+#endif
 }
 
 void
 icmpDomainPing(struct in_addr to, char *domain)
 {
+#if USE_ICMP
     debug(37, 3, "icmpDomainPing: '%s'\n", domain);
     icmpSendEcho(to, S_ICMP_DOM, domain, 0);
+#endif
 }
 
-static void
-icmpHandleSourcePing(struct sockaddr_in *from, char *buf)
+void
+icmpOpen(void)
 {
-    char *key;
-    StoreEntry *entry;
-    icp_common_t header;
-    char *url;
-    memcpy(&header, buf, sizeof(icp_common_t));
-    url = buf + sizeof(icp_common_t);
-    if (neighbors_do_private_keys && header.reqnum) {
-	key = storeGeneratePrivateKey(url, METHOD_GET, header.reqnum);
-    } else {
-	key = storeGeneratePublicKey(url, METHOD_GET);
+#if USE_ICMP
+    struct sockaddr_in S;
+    int namelen = sizeof(struct sockaddr_in);
+    pid_t pid;
+    int child_sock;
+    icmp_sock = comm_open(SOCK_DGRAM,
+	0,
+	local_addr,
+	0,
+	COMM_NONBLOCKING,
+	"ICMP Socket");
+    if (icmp_sock < 0) {
+	debug(37, 0, "icmpOpen: icmp_sock: %s\n", xstrerror());
+	return;
     }
-    debug(37, 3, "icmpHandleSourcePing: from %s, key=%s\n",
-	inet_ntoa(from->sin_addr),
-	key);
-    if ((entry = storeGet(key)) == NULL)
+    child_sock = comm_open(SOCK_DGRAM,
+	0,
+	local_addr,
+	0,
+	0,
+	"ICMP Socket");
+    if (child_sock < 0) {
+	debug(37, 0, "icmpOpen: child_sock: %s\n", xstrerror());
 	return;
-    if (entry->lock_count == 0)
+    }
+    getsockname(icmp_sock, (struct sockaddr *) &S, &namelen);
+    if (comm_connect_addr(child_sock, &S) != COMM_OK)
+	fatal_dump(xstrerror());
+    getsockname(child_sock, (struct sockaddr *) &S, &namelen);
+    if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
+	fatal_dump(xstrerror());
+    if ((pid = fork()) < 0) {
+	debug(29, 0, "icmpOpen: fork: %s\n", xstrerror());
+	comm_close(icmp_sock);
+	comm_close(child_sock);
 	return;
-    /* call neighborsUdpAck even if ping_status != PING_WAITING */
-    neighborsUdpAck(icmp_sock,
-	url,
-	&header,
-	from,
-	entry,
-	NULL,
-	0);
+    }
+    if (pid == 0) {		/* child */
+	char *x = xcalloc(strlen(Config.debugOptions) + 32, 1);
+	sprintf(x, "SQUID_DEBUG=%s\n", Config.debugOptions);
+	putenv(x);
+	comm_close(icmp_sock);
+	dup2(child_sock, 0);
+	dup2(child_sock, 1);
+	comm_close(child_sock);
+	dup2(fileno(debug_log), 2);
+	fclose(debug_log);
+	enter_suid();
+	execlp(Config.Program.pinger, "(pinger)", NULL);
+	debug(29, 0, "icmpOpen: %s: %s\n", Config.Program.pinger, xstrerror());
+	_exit(1);
+    }
+    comm_close(child_sock);
+    commSetSelect(icmp_sock,
+	COMM_SELECT_READ,
+	(PF) icmpRecv,
+	(void *) -1, 0);
+    comm_set_fd_lifetime(icmp_sock, -1);
+    debug(29, 0, "Pinger socket opened on FD %d\n", icmp_sock);
+#endif
 }
 
-#endif /* USE_ICMP */
+void
+icmpClose(void)
+{
+#if USE_ICMP
+    icmpQueueData *queue;
+    debug(29, 0, "Closing ICMP socket on FD %d\n", icmp_sock);
+    comm_close(icmp_sock);
+    commSetSelect(icmp_sock,
+	COMM_SELECT_READ,
+	NULL,
+	NULL, 0);
+    icmp_sock = -1;
+    while ((queue = IcmpQueueHead)) {
+	IcmpQueueHead = queue->next;
+	if (queue->free_func)
+	    queue->free_func(queue->msg);
+	safe_free(queue);
+    }
+#endif
+}
