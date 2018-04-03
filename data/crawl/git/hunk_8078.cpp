 	sb->buf[sb->len] = '\0';
 }
 
-void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len) {
+void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
+{
 	strbuf_grow(sb, len);
-	if (pos >= sb->len) {
-		pos = sb->len;
-	} else {
-		memmove(sb->buf + pos + len, sb->buf + pos, sb->len - pos);
-	}
+	if (pos > sb->len)
+		die("`pos' is too far after the end of the buffer");
+	memmove(sb->buf + pos + len, sb->buf + pos, sb->len - pos);
 	memcpy(sb->buf + pos, data, len);
 	strbuf_setlen(sb, sb->len + len);
 }
 
-void strbuf_add(struct strbuf *sb, const void *data, size_t len) {
+void strbuf_splice(struct strbuf *sb, size_t pos, size_t len,
+				   const void *data, size_t dlen)
+{
+	if (pos + len < pos)
+		die("you want to use way too much memory");
+	if (pos > sb->len)
+		die("`pos' is too far after the end of the buffer");
+	if (pos + len > sb->len)
+		die("`pos + len' is too far after the end of the buffer");
+
+	if (dlen >= len)
+		strbuf_grow(sb, dlen - len);
+	memmove(sb->buf + pos + dlen,
+			sb->buf + pos + len,
+			sb->len - pos - len);
+	memcpy(sb->buf + pos, data, dlen);
+	strbuf_setlen(sb, sb->len + dlen - len);
+}
+
+void strbuf_add(struct strbuf *sb, const void *data, size_t len)
+{
 	strbuf_grow(sb, len);
 	memcpy(sb->buf + sb->len, data, len);
 	strbuf_setlen(sb, sb->len + len);
 }
 
-void strbuf_addf(struct strbuf *sb, const char *fmt, ...) {
+void strbuf_addf(struct strbuf *sb, const char *fmt, ...)
+{
 	int len;
 	va_list ap;
 
