 	}
 }
 
+static inline int xdup(int fd)
+{
+	int ret = dup(fd);
+	if (ret < 0)
+		die("dup failed: %s", strerror(errno));
+	return ret;
+}
+
+static inline FILE *xfdopen(int fd, const char *mode)
+{
+	FILE *stream = fdopen(fd, mode);
+	if (stream == NULL)
+		die("Out of memory? fdopen failed: %s", strerror(errno));
+	return stream;
+}
+
 static inline size_t xsize_t(off_t len)
 {
 	return (size_t)len;