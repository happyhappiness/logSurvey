 void
 comm_close(int fd)
 {
-    FD_ENTRY *conn = NULL;
+    FD_ENTRY *fde = NULL;
     debug(5, 5, "comm_close: FD %d\n", fd);
-    if (fd < 0 || fd >= Squid_MaxFD)
-	return;
-    conn = &fd_table[fd];
-    if (!conn->openned)
+    if (fd < 0)
+    	fatal_dump("comm_close: bad FD");
+    if (fd >= Squid_MaxFD)
+    	fatal_dump("comm_close: bad FD");
+    fde = &fd_table[fd];
+    if (!fde->open)
 	return;
-    if (fdstatGetType(fd) == FD_FILE) {
-	debug(5, 0, "FD %d: Someone called comm_close() on a File\n", fd);
-	fatal_dump(NULL);
-    }
-    conn->openned = 0;
+    if (fd_table[fd].type == FD_FILE)
+	fatal_dump("comm_close: not a SOCKET");
+    fde->open = 0;
     RWStateCallbackAndFree(fd, COMM_ERROR);
     fdstat_close(fd);		/* update fdstat */
     commCallCloseHandlers(fd);
-    memset(conn, '\0', sizeof(FD_ENTRY));
+    memset(fde, '\0', sizeof(FD_ENTRY));
 #if USE_ASYNC_IO
     aioClose(fd);
 #else
-    conn->lifetime = -1;
+    fde->lifetime = -1;
     close(fd);
 #endif
 }
