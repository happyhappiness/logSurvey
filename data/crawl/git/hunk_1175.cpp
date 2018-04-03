 	const char *format;
 };
 
+static int filter_object(const char *path, unsigned mode,
+			 const unsigned char *sha1,
+			 char **buf, unsigned long *size)
+{
+	enum object_type type;
+
+	*buf = read_sha1_file(sha1, &type, size);
+	if (!*buf)
+		return error(_("cannot read object %s '%s'"),
+			sha1_to_hex(sha1), path);
+	if ((type == OBJ_BLOB) && S_ISREG(mode)) {
+		struct strbuf strbuf = STRBUF_INIT;
+		if (convert_to_working_tree(path, *buf, *size, &strbuf)) {
+			free(*buf);
+			*size = strbuf.len;
+			*buf = strbuf_detach(&strbuf, NULL);
+		}
+	}
+
+	return 0;
+}
+
 static int cat_one_file(int opt, const char *exp_type, const char *obj_name,
 			int unknown_type)
 {
