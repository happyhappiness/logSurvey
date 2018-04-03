 	*me = M;
     }
     /* fdstat update */
-    fdstat_open(sock, Socket);
+    fdstat_open(sock, FD_SOCKET);
     conn = &fd_table[sock];
     conn->openned = 1;
     conn->sender = 0;		/* This is an accept, therefore receiver. */
     conn->comm_type = listener->comm_type;
     strcpy(conn->ipaddr, inet_ntoa(P.sin_addr));
-
+    conn->remote_port = htons(P.sin_port);
+    conn->local_port = htons(M.sin_port);
     commSetNonBlocking(sock);
-
     return sock;
 }
 
 int comm_close(fd)
      int fd;
 {
     FD_ENTRY *conn = NULL;
+    struct close_handler *ch = NULL;
 
     if (fd < 0)
 	return -1;
 
-    if (fdstat_type(fd) == File) {
+    if (fdstat_type(fd) == FD_FILE) {
 	debug(5, 0, "FD %d: Someone called comm_close() on a File\n", fd);
 	fatal_dump(NULL);
     }
     conn = &fd_table[fd];
 
+    safe_free(conn->rstate);
+    safe_free(conn->wstate);
+
     comm_set_fd_lifetime(fd, -1);	/* invalidate the lifetime */
     debug(5, 5, "comm_close: FD %d\n", fd);
     /* update fdstat */
     fdstat_close(fd);
-    if (conn->close_handler)
-	conn->close_handler(fd, conn->close_data);
+    /* Call close handlers */
+    while ((ch = conn->close_handler)) {
+	conn->close_handler = ch->next;
+	ch->handler(fd, ch->data);
+	safe_free(ch);
+    }
     memset(conn, '\0', sizeof(FD_ENTRY));
     return close(fd);
 }
