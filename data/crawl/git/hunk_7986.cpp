 	}
 }
 
+/* 1 means: quote as octal
+ * 0 means: quote as octal if (quote_path_fully)
+ * -1 means: never quote
+ * c: quote as "\\c"
+ */
+#define X8(x)   x, x, x, x, x, x, x, x
+#define X16(x)  X8(x), X8(x)
+static signed char const sq_lookup[256] = {
+	/*           0    1    2    3    4    5    6    7 */
+	/* 0x00 */   1,   1,   1,   1,   1,   1,   1, 'a',
+	/* 0x08 */ 'b', 't', 'n', 'v', 'f', 'r',   1,   1,
+	/* 0x10 */ X16(1),
+	/* 0x20 */  -1,  -1, '"',  -1,  -1,  -1,  -1,  -1,
+	/* 0x28 */ X16(-1), X16(-1), X16(-1),
+	/* 0x58 */  -1,  -1,  -1,  -1,'\\',  -1,  -1,  -1,
+	/* 0x60 */ X16(-1), X8(-1),
+	/* 0x78 */  -1,  -1,  -1,  -1,  -1,  -1,  -1,   1,
+	/* 0x80 */ /* set to 0 */
+};
+
+static inline int sq_must_quote(char c) {
+	return sq_lookup[(unsigned char)c] + quote_path_fully > 0;
+}
+
+/* returns the longest prefix not needing a quote up to maxlen if positive.
+   This stops at the first \0 because it's marked as a character needing an
+   escape */
+static size_t next_quote_pos(const char *s, ssize_t maxlen)
+{
+	size_t len;
+	if (maxlen < 0) {
+		for (len = 0; !sq_must_quote(s[len]); len++);
+	} else {
+		for (len = 0; len < maxlen && !sq_must_quote(s[len]); len++);
+	}
+	return len;
+}
+
 /*
  * C-style name quoting.
  *
- * Does one of three things:
- *
- * (1) if outbuf and outfp are both NULL, inspect the input name and
- *     counts the number of bytes that are needed to hold c_style
- *     quoted version of name, counting the double quotes around
- *     it but not terminating NUL, and returns it.  However, if name
- *     does not need c_style quoting, it returns 0.
- *
- * (2) if outbuf is not NULL, it must point at a buffer large enough
- *     to hold the c_style quoted version of name, enclosing double
- *     quotes, and terminating NUL.  Fills outbuf with c_style quoted
- *     version of name enclosed in double-quote pair.  Return value
- *     is undefined.
+ * (1) if sb and fp are both NULL, inspect the input name and counts the
+ *     number of bytes that are needed to hold c_style quoted version of name,
+ *     counting the double quotes around it but not terminating NUL, and
+ *     returns it.
+ *     However, if name does not need c_style quoting, it returns 0.
  *
- * (3) if outfp is not NULL, outputs c_style quoted version of name,
- *     but not enclosed in double-quote pair.  Return value is undefined.
+ * (2) if sb or fp are not NULL, it emits the c_style quoted version
+ *     of name, enclosed with double quotes if asked and needed only.
+ *     Return value is the same as in (1).
  */
-
-static int quote_c_style_counted(const char *name, int namelen,
-				 char *outbuf, FILE *outfp, int no_dq)
+static size_t quote_c_style_counted(const char *name, ssize_t maxlen,
+                                    struct strbuf *sb, FILE *fp, int no_dq)
 {
 #undef EMIT
-#define EMIT(c) \
-	(outbuf ? (*outbuf++ = (c)) : outfp ? fputc(c, outfp) : (count++))
-
-#define EMITQ() EMIT('\\')
+#define EMIT(c)                                 \
+	do {                                        \
+		if (sb) strbuf_addch(sb, (c));          \
+		if (fp) fputc((c), fp);                 \
+		count++;                                \
+	} while (0)
+#define EMITBUF(s, l)                           \
+	do {                                        \
+		if (sb) strbuf_add(sb, (s), (l));       \
+		if (fp) fwrite((s), (l), 1, fp);        \
+		count += (l);                           \
+	} while (0)
+
+	size_t len, count = 0;
+	const char *p = name;
 
-	const char *sp;
-	unsigned char ch;
-	int count = 0, needquote = 0;
+	for (;;) {
+		int ch;
 
-	if (!no_dq)
-		EMIT('"');
-	for (sp = name; sp < name + namelen; sp++) {
-		ch = *sp;
-		if (!ch)
+		len = next_quote_pos(p, maxlen);
+		if (len == maxlen || !p[len])
 			break;
-		if ((ch < ' ') || (ch == '"') || (ch == '\\') ||
-		    (quote_path_fully && (ch >= 0177))) {
-			needquote = 1;
-			switch (ch) {
-			case '\a': EMITQ(); ch = 'a'; break;
-			case '\b': EMITQ(); ch = 'b'; break;
-			case '\f': EMITQ(); ch = 'f'; break;
-			case '\n': EMITQ(); ch = 'n'; break;
-			case '\r': EMITQ(); ch = 'r'; break;
-			case '\t': EMITQ(); ch = 't'; break;
-			case '\v': EMITQ(); ch = 'v'; break;
-
-			case '\\': /* fallthru */
-			case '"': EMITQ(); break;
-			default:
-				/* octal */
-				EMITQ();
-				EMIT(((ch >> 6) & 03) + '0');
-				EMIT(((ch >> 3) & 07) + '0');
-				ch = (ch & 07) + '0';
-				break;
-			}
+
+		if (!no_dq && p == name)
+			EMIT('"');
+
+		EMITBUF(p, len);
+		EMIT('\\');
+		p += len;
+		ch = (unsigned char)*p++;
+		if (sq_lookup[ch] >= ' ') {
+			EMIT(sq_lookup[ch]);
+		} else {
+			EMIT(((ch >> 6) & 03) + '0');
+			EMIT(((ch >> 3) & 07) + '0');
+			EMIT(((ch >> 0) & 07) + '0');
 		}
-		EMIT(ch);
 	}
+
+	EMITBUF(p, len);
+	if (p == name)   /* no ending quote needed */
+		return 0;
+
 	if (!no_dq)
 		EMIT('"');
-	if (outbuf)
-		*outbuf = 0;
+	return count;
+}
 
-	return needquote ? count : 0;
+size_t quote_c_style(const char *name, struct strbuf *sb, FILE *fp, int nodq)
+{
+	return quote_c_style_counted(name, -1, sb, fp, nodq);
 }
 
-int quote_c_style(const char *name, char *outbuf, FILE *outfp, int no_dq)
+void write_name_quoted(const char *name, FILE *fp, int terminator)
 {
-	int cnt = strlen(name);
-	return quote_c_style_counted(name, cnt, outbuf, outfp, no_dq);
+	if (terminator) {
+		quote_c_style(name, NULL, fp, 0);
+	} else {
+		fputs(name, fp);
+	}
+	fputc(terminator, fp);
+}
+
+extern void write_name_quotedpfx(const char *pfx, size_t pfxlen,
+                                 const char *name, FILE *fp, int terminator)
+{
+	int needquote = 0;
+
+	if (terminator) {
+		needquote = next_quote_pos(pfx, pfxlen) < pfxlen
+			|| name[next_quote_pos(name, -1)];
+	}
+	if (needquote) {
+		fputc('"', fp);
+		quote_c_style_counted(pfx, pfxlen, NULL, fp, 1);
+		quote_c_style(name, NULL, fp, 1);
+		fputc('"', fp);
+	} else {
+		fwrite(pfx, pfxlen, 1, fp);
+		fputs(name, fp);
+	}
+	fputc(terminator, fp);
 }
 
 /*
