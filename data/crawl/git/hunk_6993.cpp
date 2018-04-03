 		return 0;
 	return ATTR_TRUE(check[0].value);
 }
+
+struct archiver_context {
+	struct archiver_args *args;
+	write_archive_entry_fn_t write_entry;
+};
+
+static int write_archive_entry(const unsigned char *sha1, const char *base,
+		int baselen, const char *filename, unsigned mode, int stage,
+		void *context)
+{
+	static struct strbuf path = STRBUF_INIT;
+	struct archiver_context *c = context;
+	struct archiver_args *args = c->args;
+	write_archive_entry_fn_t write_entry = c->write_entry;
+	int err;
+	enum object_type type;
+	unsigned long size;
+	void *buffer;
+
+	strbuf_reset(&path);
+	strbuf_grow(&path, PATH_MAX);
+	strbuf_add(&path, base, baselen);
+	strbuf_addstr(&path, filename);
+
+	if (is_archive_path_ignored(path.buf + args->baselen))
+		return 0;
+
+	if (S_ISDIR(mode) || S_ISGITLINK(mode)) {
+		strbuf_addch(&path, '/');
+		if (args->verbose)
+			fprintf(stderr, "%.*s\n", (int)path.len, path.buf);
+		err = write_entry(args, sha1, path.buf, path.len, mode, NULL, 0);
+		if (err)
+			return err;
+		return READ_TREE_RECURSIVE;
+	}
+
+	buffer = sha1_file_to_archive(path.buf + args->baselen, sha1, mode,
+			&type, &size, args->commit);
+	if (!buffer)
+		return error("cannot read %s", sha1_to_hex(sha1));
+	if (args->verbose)
+		fprintf(stderr, "%.*s\n", (int)path.len, path.buf);
+	err = write_entry(args, sha1, path.buf, path.len, mode, buffer, size);
+	free(buffer);
+	return err;
+}
+
+int write_archive_entries(struct archiver_args *args,
+		write_archive_entry_fn_t write_entry)
+{
+	struct archiver_context context;
+	int err;
+
+	if (args->baselen > 0 && args->base[args->baselen - 1] == '/') {
+		size_t len = args->baselen;
+
+		while (len > 1 && args->base[len - 2] == '/')
+			len--;
+		if (args->verbose)
+			fprintf(stderr, "%.*s\n", (int)len, args->base);
+		err = write_entry(args, args->tree->object.sha1, args->base,
+				len, 040777, NULL, 0);
+		if (err)
+			return err;
+	}
+
+	context.args = args;
+	context.write_entry = write_entry;
+
+	err =  read_tree_recursive(args->tree, args->base, args->baselen, 0,
+			args->pathspec, write_archive_entry, &context);
+	if (err == READ_TREE_RECURSIVE)
+		err = 0;
+	return err;
+}
