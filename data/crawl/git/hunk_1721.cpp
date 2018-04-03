 	return len;
 }
 
+void write_file_buf(const char *path, const char *buf, size_t len)
+{
+	int fd = xopen(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
+	if (write_in_full(fd, buf, len) != len)
+		die_errno(_("could not write to %s"), path);
+	if (close(fd))
+		die_errno(_("could not close %s"), path);
+}
+
 void write_file(const char *path, const char *fmt, ...)
 {
 	va_list params;
 	struct strbuf sb = STRBUF_INIT;
-	int fd = xopen(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
 
 	va_start(params, fmt);
 	strbuf_vaddf(&sb, fmt, params);
 	va_end(params);
 
 	strbuf_complete_line(&sb);
-	if (write_in_full(fd, sb.buf, sb.len) != sb.len)
-		die_errno(_("could not write to %s"), path);
+
+	write_file_buf(path, sb.buf, sb.len);
 	strbuf_release(&sb);
-	if (close(fd))
-		die_errno(_("could not close %s"), path);
 }
 
 void sleep_millisec(int millisec)