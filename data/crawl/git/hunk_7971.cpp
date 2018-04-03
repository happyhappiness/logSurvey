 
 void trace_printf(const char *fmt, ...)
 {
-	char buf[8192];
+	struct strbuf buf;
 	va_list ap;
 	int fd, len, need_close = 0;
 
 	fd = get_trace_fd(&need_close);
 	if (!fd)
 		return;
 
+	strbuf_init(&buf, 0);
 	va_start(ap, fmt);
-	len = vsnprintf(buf, sizeof(buf), fmt, ap);
+	len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
 	va_end(ap);
-	if (len >= sizeof(buf))
-		die("unreasonnable trace length");
-	write_or_whine_pipe(fd, buf, len, err_msg);
+	if (len >= strbuf_avail(&buf)) {
+		strbuf_grow(&buf, len - strbuf_avail(&buf) + 128);
+		va_start(ap, fmt);
+		len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
+		va_end(ap);
+		if (len >= strbuf_avail(&buf))
+			die("broken vsnprintf");
+	}
+	strbuf_setlen(&buf, len);
+
+	write_or_whine_pipe(fd, buf.buf, buf.len, err_msg);
+	strbuf_release(&buf);
 
 	if (need_close)
 		close(fd);
 }
 
 void trace_argv_printf(const char **argv, int count, const char *fmt, ...)
 {
-	char buf[8192];
+	struct strbuf buf;
 	va_list ap;
-	char *argv_str;
-	size_t argv_len;
 	int fd, len, need_close = 0;
 
 	fd = get_trace_fd(&need_close);
 	if (!fd)
 		return;
 
+	strbuf_init(&buf, 0);
 	va_start(ap, fmt);
-	len = vsnprintf(buf, sizeof(buf), fmt, ap);
+	len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
 	va_end(ap);
-	if (len >= sizeof(buf))
-		die("unreasonnable trace length");
-
-	/* Get the argv string. */
-	argv_str = sq_quote_argv(argv, count);
-	argv_len = strlen(argv_str);
-
-	write_or_whine_pipe(fd, buf, len, err_msg);
-	write_or_whine_pipe(fd, argv_str, argv_len, err_msg);
-	write_or_whine_pipe(fd, "\n", 1, err_msg);
+	if (len >= strbuf_avail(&buf)) {
+		strbuf_grow(&buf, len - strbuf_avail(&buf) + 128);
+		va_start(ap, fmt);
+		len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
+		va_end(ap);
+		if (len >= strbuf_avail(&buf))
+			die("broken vsnprintf");
+	}
+	strbuf_setlen(&buf, len);
 
-	free(argv_str);
+	sq_quote_argv(&buf, argv, count, 0);
+	strbuf_addch(&buf, '\n');
+	write_or_whine_pipe(fd, buf.buf, buf.len, err_msg);
+	strbuf_release(&buf);
 
 	if (need_close)
 		close(fd);