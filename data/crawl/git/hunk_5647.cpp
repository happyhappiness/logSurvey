 		leaf.tree);
 }
 
+static void note_change_n(struct branch *b)
+{
+	const char *p = command_buf.buf + 2;
+	static struct strbuf uq = STRBUF_INIT;
+	struct object_entry *oe = oe;
+	struct branch *s;
+	unsigned char sha1[20], commit_sha1[20];
+	uint16_t inline_data = 0;
+
+	/* <dataref> or 'inline' */
+	if (*p == ':') {
+		char *x;
+		oe = find_mark(strtoumax(p + 1, &x, 10));
+		hashcpy(sha1, oe->sha1);
+		p = x;
+	} else if (!prefixcmp(p, "inline")) {
+		inline_data = 1;
+		p += 6;
+	} else {
+		if (get_sha1_hex(p, sha1))
+			die("Invalid SHA1: %s", command_buf.buf);
+		oe = find_object(sha1);
+		p += 40;
+	}
+	if (*p++ != ' ')
+		die("Missing space after SHA1: %s", command_buf.buf);
+
+	/* <committish> */
+	s = lookup_branch(p);
+	if (s) {
+		hashcpy(commit_sha1, s->sha1);
+	} else if (*p == ':') {
+		uintmax_t commit_mark = strtoumax(p + 1, NULL, 10);
+		struct object_entry *commit_oe = find_mark(commit_mark);
+		if (commit_oe->type != OBJ_COMMIT)
+			die("Mark :%" PRIuMAX " not a commit", commit_mark);
+		hashcpy(commit_sha1, commit_oe->sha1);
+	} else if (!get_sha1(p, commit_sha1)) {
+		unsigned long size;
+		char *buf = read_object_with_reference(commit_sha1,
+			commit_type, &size, commit_sha1);
+		if (!buf || size < 46)
+			die("Not a valid commit: %s", p);
+		free(buf);
+	} else
+		die("Invalid ref name or SHA1 expression: %s", p);
+
+	if (inline_data) {
+		static struct strbuf buf = STRBUF_INIT;
+
+		if (p != uq.buf) {
+			strbuf_addstr(&uq, p);
+			p = uq.buf;
+		}
+		read_next_command();
+		parse_data(&buf);
+		store_object(OBJ_BLOB, &buf, &last_blob, sha1, 0);
+	} else if (oe) {
+		if (oe->type != OBJ_BLOB)
+			die("Not a blob (actually a %s): %s",
+				typename(oe->type), command_buf.buf);
+	} else {
+		enum object_type type = sha1_object_info(sha1, NULL);
+		if (type < 0)
+			die("Blob not found: %s", command_buf.buf);
+		if (type != OBJ_BLOB)
+			die("Not a blob (actually a %s): %s",
+			    typename(type), command_buf.buf);
+	}
+
+	tree_content_set(&b->branch_tree, sha1_to_hex(commit_sha1), sha1,
+		S_IFREG | 0644, NULL);
+}
+
 static void file_change_deleteall(struct branch *b)
 {
 	release_tree_content_recursive(b->branch_tree.tree);
