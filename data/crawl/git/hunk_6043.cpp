 	NULL
 };
 
+static void mktree_line(char *buf, size_t len, int line_termination)
+{
+	char *ptr, *ntr;
+	unsigned mode;
+	enum object_type type;
+	char *path;
+	unsigned char sha1[20];
+
+	ptr = buf;
+	/*
+	 * Read non-recursive ls-tree output format:
+	 *     mode SP type SP sha1 TAB name
+	 */
+	mode = strtoul(ptr, &ntr, 8);
+	if (ptr == ntr || !ntr || *ntr != ' ')
+		die("input format error: %s", buf);
+	ptr = ntr + 1; /* type */
+	ntr = strchr(ptr, ' ');
+	if (!ntr || buf + len <= ntr + 40 ||
+	    ntr[41] != '\t' ||
+	    get_sha1_hex(ntr + 1, sha1))
+		die("input format error: %s", buf);
+	type = sha1_object_info(sha1, NULL);
+	if (type < 0)
+		die("object %s unavailable", sha1_to_hex(sha1));
+	*ntr++ = 0; /* now at the beginning of SHA1 */
+	if (type != type_from_string(ptr))
+		die("object type %s mismatch (%s)", ptr, typename(type));
+
+	path = ntr + 41;  /* at the beginning of name */
+	if (line_termination && path[0] == '"') {
+		struct strbuf p_uq = STRBUF_INIT;
+		if (unquote_c_style(&p_uq, path, NULL))
+			die("invalid quoting");
+		path = strbuf_detach(&p_uq, NULL);
+	}
+	append_to_tree(mode, sha1, path);
+}
+
 int cmd_mktree(int ac, const char **av, const char *prefix)
 {
 	struct strbuf sb = STRBUF_INIT;
-	struct strbuf p_uq = STRBUF_INIT;
 	unsigned char sha1[20];
 	int line_termination = '\n';
 	const struct option option[] = {
