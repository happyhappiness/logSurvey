 	free(cl_separators);
 }
 
-static struct strbuf **read_input_file(const char *file)
+static void read_input_file(struct strbuf *sb, const char *file)
 {
-	struct strbuf **lines;
-	struct strbuf sb = STRBUF_INIT;
-
 	if (file) {
-		if (strbuf_read_file(&sb, file, 0) < 0)
+		if (strbuf_read_file(sb, file, 0) < 0)
 			die_errno(_("could not read input file '%s'"), file);
 	} else {
-		if (strbuf_read(&sb, fileno(stdin), 0) < 0)
+		if (strbuf_read(sb, fileno(stdin), 0) < 0)
 			die_errno(_("could not read from stdin"));
 	}
+}
 
-	lines = strbuf_split(&sb, '\n');
+static const char *next_line(const char *str)
+{
+	const char *nl = strchrnul(str, '\n');
+	return nl + !!*nl;
+}
 
-	strbuf_release(&sb);
+/*
+ * Return the position of the start of the last line. If len is 0, return -1.
+ */
+static int last_line(const char *buf, size_t len)
+{
+	int i;
+	if (len == 0)
+		return -1;
+	if (len == 1)
+		return 0;
+	/*
+	 * Skip the last character (in addition to the null terminator),
+	 * because if the last character is a newline, it is considered as part
+	 * of the last line anyway.
+	 */
+	i = len - 2;
 
-	return lines;
+	for (; i >= 0; i--) {
+		if (buf[i] == '\n')
+			return i + 1;
+	}
+	return 0;
 }
 
 /*
- * Return the (0 based) index of the start of the patch or the line
- * count if there is no patch in the message.
+ * Return the position of the start of the patch or the length of str if there
+ * is no patch in the message.
  */
-static int find_patch_start(struct strbuf **lines, int count)
+static int find_patch_start(const char *str)
 {
-	int i;
+	const char *s;
 
-	/* Get the start of the patch part if any */
-	for (i = 0; i < count; i++) {
-		if (starts_with(lines[i]->buf, "---"))
-			return i;
+	for (s = str; *s; s = next_line(s)) {
+		if (starts_with(s, "---"))
+			return s - str;
 	}
 
-	return count;
+	return s - str;
 }
 
 /*
- * Return the (0 based) index of the first trailer line or count if
- * there are no trailers. Trailers are searched only in the lines from
- * index (count - 1) down to index 0.
+ * Return the position of the first trailer line or len if there are no
+ * trailers.
  */
-static int find_trailer_start(struct strbuf **lines, int count)
+static int find_trailer_start(const char *buf, size_t len)
 {
-	int start, end_of_title, only_spaces = 1;
+	const char *s;
+	int end_of_title, l, only_spaces = 1;
 	int recognized_prefix = 0, trailer_lines = 0, non_trailer_lines = 0;
 	/*
 	 * Number of possible continuation lines encountered. This will be
