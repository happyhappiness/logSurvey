 	return c;
 }
 
+static void status_vprintf(struct wt_status *s, int at_bol, const char *color,
+		const char *fmt, va_list ap, const char *trail)
+{
+	struct strbuf sb = STRBUF_INIT;
+	struct strbuf linebuf = STRBUF_INIT;
+	const char *line, *eol;
+
+	strbuf_vaddf(&sb, fmt, ap);
+	if (!sb.len) {
+		strbuf_addch(&sb, '#');
+		if (!trail)
+			strbuf_addch(&sb, ' ');
+		color_print_strbuf(s->fp, color, &sb);
+		if (trail)
+			fprintf(s->fp, "%s", trail);
+		strbuf_release(&sb);
+		return;
+	}
+	for (line = sb.buf; *line; line = eol + 1) {
+		eol = strchr(line, '\n');
+
+		strbuf_reset(&linebuf);
+		if (at_bol) {
+			strbuf_addch(&linebuf, '#');
+			if (*line != '\n' && *line != '\t')
+				strbuf_addch(&linebuf, ' ');
+		}
+		if (eol)
+			strbuf_add(&linebuf, line, eol - line);
+		else
+			strbuf_addstr(&linebuf, line);
+		color_print_strbuf(s->fp, color, &linebuf);
+		if (eol)
+			fprintf(s->fp, "\n");
+		else
+			break;
+		at_bol = 1;
+	}
+	if (trail)
+		fprintf(s->fp, "%s", trail);
+	strbuf_release(&linebuf);
+	strbuf_release(&sb);
+}
+
+void status_printf_ln(struct wt_status *s, const char *color,
+			const char *fmt, ...)
+{
+	va_list ap;
+
+	va_start(ap, fmt);
+	status_vprintf(s, 1, color, fmt, ap, "\n");
+	va_end(ap);
+}
+
+void status_printf(struct wt_status *s, const char *color,
+			const char *fmt, ...)
+{
+	va_list ap;
+
+	va_start(ap, fmt);
+	status_vprintf(s, 1, color, fmt, ap, NULL);
+	va_end(ap);
+}
+
+void status_printf_more(struct wt_status *s, const char *color,
+			const char *fmt, ...)
+{
+	va_list ap;
+
+	va_start(ap, fmt);
+	status_vprintf(s, 0, color, fmt, ap, NULL);
+	va_end(ap);
+}
+
 void wt_status_prepare(struct wt_status *s)
 {
 	unsigned char sha1[20];
