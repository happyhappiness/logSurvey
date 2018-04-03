 		strbuf_addch(out, '\n');
 	else
 		strbuf_addf(out, " into %s\n", current_branch);
+}
+
+static int do_fmt_merge_msg(int merge_summary, struct strbuf *in,
+	struct strbuf *out) {
+	int limit = 20, i = 0, pos = 0;
+	unsigned char head_sha1[20];
+	const char *current_branch;
+
+	/* get current branch */
+	current_branch = resolve_ref("HEAD", head_sha1, 1, NULL);
+	if (!current_branch)
+		die("No current branch");
+	if (!prefixcmp(current_branch, "refs/heads/"))
+		current_branch += 11;
+
+	/* get a line */
+	while (pos < in->len) {
+		int len;
+		char *newline, *p = in->buf + pos;
+
+		newline = strchr(p, '\n');
+		len = newline ? newline - p : strlen(p);
+		pos += len + !!newline;
+		i++;
+		p[len] = 0;
+		if (handle_line(p))
+			die ("Error in line %d: %.*s", i, len, p);
+	}
+
+	if (!srcs.nr)
+		return 0;
+
+	do_fmt_merge_msg_title(out, current_branch);
 
 	if (merge_summary) {
 		struct commit *head;