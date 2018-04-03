 void
 file_close(int fd)
 {
-    FD_ENTRY *fde = NULL;
-    if (fd < 0)
-	fatal_dump("file_close: bad file number");
-    fde = &fd_table[fd];
-    if (!fde->open)
-	fatal_dump("file_close: already closed");
+    FD_ENTRY *fde = &fd_table[fd];
+    assert(fd >= 0);
+    assert(fde->open);
     if (BIT_TEST(fde->flags, FD_WRITE_DAEMON)) {
 	BIT_SET(fde->flags, FD_CLOSE_REQUEST);
 	return;
