 	return clean_merge;
 }
 
-static unsigned char *stage_sha(const unsigned char *sha, unsigned mode)
+static struct object_id *stage_oid(const struct object_id *oid, unsigned mode)
 {
-	return (is_null_sha1(sha) || mode == 0) ? NULL: (unsigned char *)sha;
+	return (is_null_oid(oid) || mode == 0) ? NULL: (struct object_id *)oid;
 }
 
-static int read_sha1_strbuf(const unsigned char *sha1, struct strbuf *dst)
+static int read_oid_strbuf(const struct object_id *oid, struct strbuf *dst)
 {
 	void *buf;
 	enum object_type type;
 	unsigned long size;
-	buf = read_sha1_file(sha1, &type, &size);
+	buf = read_sha1_file(oid->hash, &type, &size);
 	if (!buf)
-		return error(_("cannot read object %s"), sha1_to_hex(sha1));
+		return error(_("cannot read object %s"), oid_to_hex(oid));
 	if (type != OBJ_BLOB) {
 		free(buf);
-		return error(_("object %s is not a blob"), sha1_to_hex(sha1));
+		return error(_("object %s is not a blob"), oid_to_hex(oid));
 	}
 	strbuf_attach(dst, buf, size, size + 1);
 	return 0;
 }
 
-static int blob_unchanged(const unsigned char *o_sha,
+static int blob_unchanged(const struct object_id *o_oid,
 			  unsigned o_mode,
-			  const unsigned char *a_sha,
+			  const struct object_id *a_oid,
 			  unsigned a_mode,
 			  int renormalize, const char *path)
 {
