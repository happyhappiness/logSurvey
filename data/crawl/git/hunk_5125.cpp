 {
 	const unsigned char *repl = lookup_replace_object(sha1);
 	void *data = read_object(repl, type, size);
+	char *path;
 
 	/* die if we replaced an object with one that does not exist */
 	if (!data && repl != sha1)
 		die("replacement %s not found for %s",
 		    sha1_to_hex(repl), sha1_to_hex(sha1));
 
 	/* legacy behavior is to die on corrupted objects */
-	if (!data && (has_loose_object(repl) || has_packed_and_bad(repl)))
-		die("object %s is corrupted", sha1_to_hex(repl));
+	if (!data) {
+		if (has_loose_object(repl)) {
+			path = sha1_file_name(sha1);
+			die("loose object %s (stored in %s) is corrupted", sha1_to_hex(repl), path);
+		}
+		if (has_packed_and_bad(repl)) {
+			path = sha1_pack_name(sha1);
+			die("packed object %s (stored in %s) is corrupted", sha1_to_hex(repl), path);
+		}
+	}
 
 	if (replacement)
 		*replacement = repl;