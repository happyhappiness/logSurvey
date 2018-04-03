 		unread_command_buf = 1;
 }
 
+static void cat_blob_write(const char *buf, unsigned long size)
+{
+	if (write_in_full(cat_blob_fd, buf, size) != size)
+		die_errno("Write to frontend failed");
+}
+
+static void cat_blob(struct object_entry *oe, unsigned char sha1[20])
+{
+	struct strbuf line = STRBUF_INIT;
+	unsigned long size;
+	enum object_type type = 0;
+	char *buf;
+
+	if (!oe || oe->pack_id == MAX_PACK_ID) {
+		buf = read_sha1_file(sha1, &type, &size);
+	} else {
+		type = oe->type;
+		buf = gfi_unpack_entry(oe, &size);
+	}
+
+	/*
+	 * Output based on batch_one_object() from cat-file.c.
+	 */
+	if (type <= 0) {
+		strbuf_reset(&line);
+		strbuf_addf(&line, "%s missing\n", sha1_to_hex(sha1));
+		cat_blob_write(line.buf, line.len);
+		strbuf_release(&line);
+		free(buf);
+		return;
+	}
+	if (!buf)
+		die("Can't read object %s", sha1_to_hex(sha1));
+	if (type != OBJ_BLOB)
+		die("Object %s is a %s but a blob was expected.",
+		    sha1_to_hex(sha1), typename(type));
+	strbuf_reset(&line);
+	strbuf_addf(&line, "%s %s %lu\n", sha1_to_hex(sha1),
+						typename(type), size);
+	cat_blob_write(line.buf, line.len);
+	strbuf_release(&line);
+	cat_blob_write(buf, size);
+	cat_blob_write("\n", 1);
+	free(buf);
+}
+
+static void parse_cat_blob(void)
+{
+	const char *p;
+	struct object_entry *oe = oe;
+	unsigned char sha1[20];
+
+	/* cat-blob SP <object> LF */
+	p = command_buf.buf + strlen("cat-blob ");
+	if (*p == ':') {
+		char *x;
+		oe = find_mark(strtoumax(p + 1, &x, 10));
+		if (x == p + 1)
+			die("Invalid mark: %s", command_buf.buf);
+		if (!oe)
+			die("Unknown mark: %s", command_buf.buf);
+		if (*x)
+			die("Garbage after mark: %s", command_buf.buf);
+		hashcpy(sha1, oe->idx.sha1);
+	} else {
+		if (get_sha1_hex(p, sha1))
+			die("Invalid SHA1: %s", command_buf.buf);
+		if (p[40])
+			die("Garbage after SHA1: %s", command_buf.buf);
+		oe = find_object(sha1);
+	}
+
+	cat_blob(oe, sha1);
+}
+
 static void parse_checkpoint(void)
 {
 	if (object_count) {
