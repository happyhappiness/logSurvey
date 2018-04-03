 
 static int populate_from_stdin(struct diff_filespec *s)
 {
-#define INCREMENT 1024
-	char *buf;
-	unsigned long size;
-	ssize_t got;
-
-	size = 0;
-	buf = NULL;
-	while (1) {
-		buf = xrealloc(buf, size + INCREMENT);
-		got = xread(0, buf + size, INCREMENT);
-		if (!got)
-			break; /* EOF */
-		if (got < 0)
-			return error("error while reading from stdin %s",
+	struct strbuf buf;
+
+	strbuf_init(&buf);
+	if (strbuf_read(&buf, 0) < 0)
+		return error("error while reading from stdin %s",
 				     strerror(errno));
-		size += got;
-	}
+
 	s->should_munmap = 0;
-	s->data = buf;
-	s->size = size;
+	s->size = buf.len;
+	s->data = strbuf_detach(&buf);
 	s->should_free = 1;
 	return 0;
 }