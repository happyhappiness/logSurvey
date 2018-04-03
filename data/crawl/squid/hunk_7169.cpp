 {
     FD_ENTRY *fde = NULL;
     debug(5, 5) ("comm_close: FD %d\n", fd);
-    if (fd < 0)
-	fatal_dump("comm_close: bad FD");
-    if (fd >= Squid_MaxFD)
-	fatal_dump("comm_close: bad FD");
+    assert(fd >= 0);
+    assert(fd < Squid_MaxFD);
     fde = &fd_table[fd];
     if (!fde->open)
 	return;
-    if (fd_table[fd].type == FD_FILE)
-	fatal_dump("comm_close: not a SOCKET");
+    assert(fd_table[fd].type =! FD_FILE);
     fde->open = 0;
     CommWriteStateCallbackAndFree(fd, COMM_ERROR);
     commCallCloseHandlers(fd);
