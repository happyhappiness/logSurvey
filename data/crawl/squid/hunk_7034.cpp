     FREE * free_func)
 {
     dwrite_q *wq = NULL;
-    fde *F;
-    if (fd < 0)
-	fatal_dump("file_write: bad FD");
-    F = &fd_table[fd];
-    if (!F->open) {
-	debug_trap("file_write: FILE_NOT_OPEN");
-	return DISK_ERROR;
-    }
+    fde *F = &fd_table[fd];
+    assert(fd >= 0);
+    assert(F->open);
     /* if we got here. Caller is eligible to write. */
     wq = xcalloc(1, sizeof(dwrite_q));
     wq->buf = ptr_to_buf;
