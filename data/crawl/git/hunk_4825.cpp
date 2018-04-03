 
 void strbuf_addf(struct strbuf *sb, const char *fmt, ...)
 {
-	int len;
 	va_list ap;
+	va_start(ap, fmt);
+	strbuf_vaddf(sb, fmt, ap);
+	va_end(ap);
+}
+
+void strbuf_vaddf(struct strbuf *sb, const char *fmt, va_list ap)
+{
+	int len;
+	va_list cp;
 
 	if (!strbuf_avail(sb))
 		strbuf_grow(sb, 64);
-	va_start(ap, fmt);
-	len = vsnprintf(sb->buf + sb->len, sb->alloc - sb->len, fmt, ap);
-	va_end(ap);
+	va_copy(cp, ap);
+	len = vsnprintf(sb->buf + sb->len, sb->alloc - sb->len, fmt, cp);
+	va_end(cp);
 	if (len < 0)
-		die("your vsnprintf is broken");
+		die("BUG: your vsnprintf is broken (returned %d)", len);
 	if (len > strbuf_avail(sb)) {
 		strbuf_grow(sb, len);
-		va_start(ap, fmt);
 		len = vsnprintf(sb->buf + sb->len, sb->alloc - sb->len, fmt, ap);
-		va_end(ap);
-		if (len > strbuf_avail(sb)) {
-			die("this should not happen, your snprintf is broken");
-		}
+		if (len > strbuf_avail(sb))
+			die("BUG: your vsnprintf is broken (insatiable)");
 	}
 	strbuf_setlen(sb, sb->len + len);
 }
