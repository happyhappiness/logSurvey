 	 */
 	if (type <= 0) {
 		strbuf_reset(&line);
-		strbuf_addf(&line, "%s missing\n", sha1_to_hex(sha1));
+		strbuf_addf(&line, "%s missing\n", oid_to_hex(oid));
 		cat_blob_write(line.buf, line.len);
 		strbuf_release(&line);
 		free(buf);
 		return;
 	}
 	if (!buf)
-		die("Can't read object %s", sha1_to_hex(sha1));
+		die("Can't read object %s", oid_to_hex(oid));
 	if (type != OBJ_BLOB)
 		die("Object %s is a %s but a blob was expected.",
-		    sha1_to_hex(sha1), typename(type));
+		    oid_to_hex(oid), typename(type));
 	strbuf_reset(&line);
-	strbuf_addf(&line, "%s %s %lu\n", sha1_to_hex(sha1),
+	strbuf_addf(&line, "%s %s %lu\n", oid_to_hex(oid),
 						typename(type), size);
 	cat_blob_write(line.buf, line.len);
 	strbuf_release(&line);
