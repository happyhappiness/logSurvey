 	return fd;
 }
 
+int xmkstemp_mode(char *template, int mode)
+{
+	int fd;
+
+	fd = git_mkstemp_mode(template, mode);
+	if (fd < 0)
+		die_errno("Unable to create temporary file");
+	return fd;
+}
+
 /*
  * zlib wrappers to make sure we don't silently miss errors
  * at init time.