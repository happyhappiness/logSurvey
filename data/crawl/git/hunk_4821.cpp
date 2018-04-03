 	cat_blob(oe, sha1);
 }
 
+static struct object_entry *dereference(struct object_entry *oe,
+					unsigned char sha1[20])
+{
+	unsigned long size;
+	void *buf = NULL;
+	if (!oe) {
+		enum object_type type = sha1_object_info(sha1, NULL);
+		if (type < 0)
+			die("object not found: %s", sha1_to_hex(sha1));
+		/* cache it! */
+		oe = insert_object(sha1);
+		oe->type = type;
+		oe->pack_id = MAX_PACK_ID;
+		oe->idx.offset = 1;
+	}
+	switch (oe->type) {
+	case OBJ_TREE:	/* easy case. */
+		return oe;
+	case OBJ_COMMIT:
+	case OBJ_TAG:
+		break;
+	default:
+		die("Not a treeish: %s", command_buf.buf);
+	}
+
+	if (oe->pack_id != MAX_PACK_ID) {	/* in a pack being written */
+		buf = gfi_unpack_entry(oe, &size);
+	} else {
+		enum object_type unused;
+		buf = read_sha1_file(sha1, &unused, &size);
+	}
+	if (!buf)
+		die("Can't load object %s", sha1_to_hex(sha1));
+
+	/* Peel one layer. */
+	switch (oe->type) {
+	case OBJ_TAG:
+		if (size < 40 + strlen("object ") ||
+		    get_sha1_hex(buf + strlen("object "), sha1))
+			die("Invalid SHA1 in tag: %s", command_buf.buf);
+		break;
+	case OBJ_COMMIT:
+		if (size < 40 + strlen("tree ") ||
+		    get_sha1_hex(buf + strlen("tree "), sha1))
+			die("Invalid SHA1 in commit: %s", command_buf.buf);
+	}
+
+	free(buf);
+	return find_object(sha1);
+}
+
+static struct object_entry *parse_treeish_dataref(const char **p)
+{
+	unsigned char sha1[20];
+	struct object_entry *e;
+
+	if (**p == ':') {	/* <mark> */
+		char *endptr;
+		e = find_mark(strtoumax(*p + 1, &endptr, 10));
+		if (endptr == *p + 1)
+			die("Invalid mark: %s", command_buf.buf);
+		if (!e)
+			die("Unknown mark: %s", command_buf.buf);
+		*p = endptr;
+		hashcpy(sha1, e->idx.sha1);
+	} else {	/* <sha1> */
+		if (get_sha1_hex(*p, sha1))
+			die("Invalid SHA1: %s", command_buf.buf);
+		e = find_object(sha1);
+		*p += 40;
+	}
+
+	while (!e || e->type != OBJ_TREE)
+		e = dereference(e, sha1);
+	return e;
+}
+
+static void print_ls(int mode, const unsigned char *sha1, const char *path)
+{
+	static struct strbuf line = STRBUF_INIT;
+
+	/* See show_tree(). */
+	const char *type =
+		S_ISGITLINK(mode) ? commit_type :
+		S_ISDIR(mode) ? tree_type :
+		blob_type;
+
+	if (!mode) {
+		/* missing SP path LF */
+		strbuf_reset(&line);
+		strbuf_addstr(&line, "missing ");
+		quote_c_style(path, &line, NULL, 0);
+		strbuf_addch(&line, '\n');
+	} else {
+		/* mode SP type SP object_name TAB path LF */
+		strbuf_reset(&line);
+		strbuf_addf(&line, "%06o %s %s\t",
+				mode, type, sha1_to_hex(sha1));
+		quote_c_style(path, &line, NULL, 0);
+		strbuf_addch(&line, '\n');
+	}
+	cat_blob_write(line.buf, line.len);
+}
+
+static void parse_ls(struct branch *b)
+{
+	const char *p;
+	struct tree_entry *root = NULL;
+	struct tree_entry leaf = {0};
+
+	/* ls SP (<treeish> SP)? <path> */
+	p = command_buf.buf + strlen("ls ");
+	if (*p == '"') {
+		if (!b)
+			die("Not in a commit: %s", command_buf.buf);
+		root = &b->branch_tree;
+	} else {
+		struct object_entry *e = parse_treeish_dataref(&p);
+		root = new_tree_entry();
+		hashcpy(root->versions[1].sha1, e->idx.sha1);
+		load_tree(root);
+		if (*p++ != ' ')
+			die("Missing space after tree-ish: %s", command_buf.buf);
+	}
+	if (*p == '"') {
+		static struct strbuf uq = STRBUF_INIT;
+		const char *endp;
+		strbuf_reset(&uq);
+		if (unquote_c_style(&uq, p, &endp))
+			die("Invalid path: %s", command_buf.buf);
+		if (*endp)
+			die("Garbage after path in: %s", command_buf.buf);
+		p = uq.buf;
+	}
+	tree_content_get(root, p, &leaf);
+	/*
+	 * A directory in preparation would have a sha1 of zero
+	 * until it is saved.  Save, for simplicity.
+	 */
+	if (S_ISDIR(leaf.versions[1].mode))
+		store_tree(&leaf);
+
+	print_ls(leaf.versions[1].mode, leaf.versions[1].sha1, p);
+	if (!b || root != &b->branch_tree)
+		release_tree_entry(root);
+}
+
 static void checkpoint(void)
 {
 	checkpoint_requested = 0;
