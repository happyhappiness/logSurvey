 	load_tree(&b->branch_tree);
 }
 
+static void cmd_from_commit(struct branch *b, char *buf, unsigned long size)
+{
+	if (!buf || size < 46)
+		die("Not a valid commit: %s", sha1_to_hex(b->sha1));
+	if (memcmp("tree ", buf, 5)
+		|| get_sha1_hex(buf + 5, b->branch_tree.versions[1].sha1))
+		die("The commit %s is corrupt", sha1_to_hex(b->sha1));
+	hashcpy(b->branch_tree.versions[0].sha1,
+		b->branch_tree.versions[1].sha1);
+}
+
+static void cmd_from_existing(struct branch *b)
+{
+	if (is_null_sha1(b->sha1)) {
+		hashclr(b->branch_tree.versions[0].sha1);
+		hashclr(b->branch_tree.versions[1].sha1);
+	} else {
+		unsigned long size;
+		char *buf;
+
+		buf = read_object_with_reference(b->sha1,
+			commit_type, &size, b->sha1);
+		cmd_from_commit(b, buf, size);
+		free(buf);
+	}
+}
+
 static void cmd_from(struct branch *b)
 {
 	const char *from;
