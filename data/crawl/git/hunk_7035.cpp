 	strbuf_addch(&buffer, '\n');
 
 	/* And add the comment */
-	if (strbuf_read(&buffer, 0, 0) < 0)
-		die("git-commit-tree: read returned %s", strerror(errno));
+	strbuf_addstr(&buffer, msg);
 
 	/* And check the encoding */
 	if (encoding_is_utf8 && !is_utf8(buffer.buf))
 		fprintf(stderr, commit_utf8_warn);
 
-	if (!write_sha1_file(buffer.buf, buffer.len, commit_type, commit_sha1)) {
+	return write_sha1_file(buffer.buf, buffer.len, commit_type, ret);
+}
+
+int cmd_commit_tree(int argc, const char **argv, const char *prefix)
+{
+	int i;
+	struct commit_list *parents = NULL;
+	unsigned char tree_sha1[20];
+	unsigned char commit_sha1[20];
+	struct strbuf buffer = STRBUF_INIT;
+
+	git_config(git_default_config, NULL);
+
+	if (argc < 2)
+		usage(commit_tree_usage);
+	if (get_sha1(argv[1], tree_sha1))
+		die("Not a valid object name %s", argv[1]);
+
+	for (i = 2; i < argc; i += 2) {
+		unsigned char sha1[20];
+		const char *a, *b;
+		a = argv[i]; b = argv[i+1];
+		if (!b || strcmp(a, "-p"))
+			usage(commit_tree_usage);
+
+		if (get_sha1(b, sha1))
+			die("Not a valid object name %s", b);
+		check_valid(sha1, OBJ_COMMIT);
+		new_parent(lookup_commit(sha1), &parents);
+	}
+
+	if (strbuf_read(&buffer, 0, 0) < 0)
+		die("git-commit-tree: read returned %s", strerror(errno));
+
+	if (!commit_tree(buffer.buf, tree_sha1, parents, commit_sha1)) {
 		printf("%s\n", sha1_to_hex(commit_sha1));
 		return 0;
 	}
