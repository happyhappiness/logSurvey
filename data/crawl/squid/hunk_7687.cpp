     FD_ENTRY *conn;
     int fd;
 
+    if (mode & O_RDWR)
+	fatal_dump("file_open: O_RDWR not allowed");
+    if (mode & O_WRONLY)
+	mode |= O_APPEND;
+    mode |= O_NDELAY;
+
     /* Open file */
-    if ((fd = open(path, mode | O_NDELAY, 0644)) < 0) {
+    if ((fd = open(path, mode, 0644)) < 0) {
 	debug(6, 0, "file_open: error opening file %s: %s\n",
 	    path, xstrerror());
 	return (DISK_ERROR);
