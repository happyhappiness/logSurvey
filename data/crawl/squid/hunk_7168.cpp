 {
     FD_ENTRY *fde;
     debug(5, 3) ("commSetTimeout: FD %d timeout %d\n", fd, timeout);
-    if (fd < 0 || fd > Squid_MaxFD)
-	fatal_dump("commSetTimeout: bad FD");
+    assert(fd >= 0);
+    assert(fd < Squid_MaxFD);
     fde = &fd_table[fd];
     if (timeout < 0) {
 	fde->timeout_handler = NULL;
