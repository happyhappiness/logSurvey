 
 void trace_printf(const char *fmt, ...)
 {
-	struct strbuf buf;
+	struct strbuf buf = STRBUF_INIT;
 	va_list ap;
-	int fd, len, need_close = 0;
+	int fd, need_close = 0;
 
 	fd = get_trace_fd(&need_close);
 	if (!fd)
 		return;
 
 	set_try_to_free_routine(NULL);	/* is never reset */
-	strbuf_init(&buf, 64);
 	va_start(ap, fmt);
-	len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
+	strbuf_vaddf(&buf, fmt, ap);
 	va_end(ap);
-	if (len >= strbuf_avail(&buf)) {
-		strbuf_grow(&buf, len - strbuf_avail(&buf) + 128);
-		va_start(ap, fmt);
-		len = vsnprintf(buf.buf, strbuf_avail(&buf), fmt, ap);
-		va_end(ap);
-		if (len >= strbuf_avail(&buf))
-			die("broken vsnprintf");
-	}
-	strbuf_setlen(&buf, len);
 
 	write_or_whine_pipe(fd, buf.buf, buf.len, err_msg);
 	strbuf_release(&buf);
