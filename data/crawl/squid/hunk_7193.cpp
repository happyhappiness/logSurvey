 comm_close(int fd)
 {
     FD_ENTRY *fde = NULL;
-    debug(5, 5, "comm_close: FD %d\n", fd);
+    debug(5, 5) ("comm_close: FD %d\n", fd);
     if (fd < 0)
 	fatal_dump("comm_close: bad FD");
     if (fd >= Squid_MaxFD)
