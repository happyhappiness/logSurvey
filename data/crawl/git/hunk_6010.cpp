 void *read_sha1_file(const unsigned char *sha1, enum object_type *type,
 		     unsigned long *size)
 {
-	void *data = read_object(sha1, type, size);
+	const unsigned char *repl = lookup_replace_object(sha1);
+	void *data = read_object(repl, type, size);
+
+	/* die if we replaced an object with one that does not exist */
+	if (!data && repl != sha1)
+		die("replacement %s not found for %s",
+		    sha1_to_hex(repl), sha1_to_hex(sha1));
+
 	/* legacy behavior is to die on corrupted objects */
-	if (!data && (has_loose_object(sha1) || has_packed_and_bad(sha1)))
-		die("object %s is corrupted", sha1_to_hex(sha1));
+	if (!data && (has_loose_object(repl) || has_packed_and_bad(repl)))
+		die("object %s is corrupted", sha1_to_hex(repl));
+
 	return data;
 }
 