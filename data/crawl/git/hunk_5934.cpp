 {
 	int ret = dup(fd);
 	if (ret < 0)
-		die("dup failed: %s", strerror(errno));
+		die_errno("dup failed");
 	return ret;
 }
 
 FILE *xfdopen(int fd, const char *mode)
 {
 	FILE *stream = fdopen(fd, mode);
 	if (stream == NULL)
-		die("Out of memory? fdopen failed: %s", strerror(errno));
+		die_errno("Out of memory? fdopen failed");
 	return stream;
 }
 
