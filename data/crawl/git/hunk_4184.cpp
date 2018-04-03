 	return contains_recurse(candidate, want);
 }
 
+static void show_tag_lines(const unsigned char *sha1, int lines)
+{
+	int i;
+	unsigned long size;
+	enum object_type type;
+	char *buf, *sp, *eol;
+	size_t len;
+
+	buf = read_sha1_file(sha1, &type, &size);
+	if (!buf || !size)
+		return;
+
+	/* skip header */
+	sp = strstr(buf, "\n\n");
+	if (!sp) {
+		free(buf);
+		return;
+	}
+	/* only take up to "lines" lines, and strip the signature */
+	size = parse_signature(buf, size);
+	for (i = 0, sp += 2; i < lines && sp < buf + size; i++) {
+		if (i)
+			printf("\n    ");
+		eol = memchr(sp, '\n', size - (sp - buf));
+		len = eol ? eol - sp : size - (sp - buf);
+		fwrite(sp, len, 1, stdout);
+		if (!eol)
+			break;
+		sp = eol + 1;
+	}
+	free(buf);
+}
+
 static int show_reference(const char *refname, const unsigned char *sha1,
 			  int flag, void *cb_data)
 {
 	struct tag_filter *filter = cb_data;
 
 	if (match_pattern(filter->patterns, refname)) {
-		int i;
-		unsigned long size;
-		enum object_type type;
-		char *buf, *sp, *eol;
-		size_t len;
-
 		if (filter->with_commit) {
 			struct commit *commit;
 
