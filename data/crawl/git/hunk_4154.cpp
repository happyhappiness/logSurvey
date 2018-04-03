 	return do_change_note_fanout(root, root, hex_sha1, 0, path, 0, fanout);
 }
 
+/*
+ * Given a pointer into a string, parse a mark reference:
+ *
+ *   idnum ::= ':' bigint;
+ *
+ * Return the first character after the value in *endptr.
+ *
+ * Complain if the following character is not what is expected,
+ * either a space or end of the string.
+ */
+static uintmax_t parse_mark_ref(const char *p, char **endptr)
+{
+	uintmax_t mark;
+
+	assert(*p == ':');
+	p++;
+	mark = strtoumax(p, endptr, 10);
+	if (*endptr == p)
+		die("No value after ':' in mark: %s", command_buf.buf);
+	return mark;
+}
+
+/*
+ * Parse the mark reference, and complain if this is not the end of
+ * the string.
+ */
+static uintmax_t parse_mark_ref_eol(const char *p)
+{
+	char *end;
+	uintmax_t mark;
+
+	mark = parse_mark_ref(p, &end);
+	if (*end != '\0')
+		die("Garbage after mark: %s", command_buf.buf);
+	return mark;
+}
+
+/*
+ * Parse the mark reference, demanding a trailing space.  Return a
+ * pointer to the space.
+ */
+static uintmax_t parse_mark_ref_space(const char **p)
+{
+	uintmax_t mark;
+	char *end;
+
+	mark = parse_mark_ref(*p, &end);
+	if (*end != ' ')
+		die("Missing space after mark: %s", command_buf.buf);
+	*p = end;
+	return mark;
+}
+
 static void file_change_m(struct branch *b)
 {
 	const char *p = command_buf.buf + 2;
