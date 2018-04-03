 	const unsigned char *repl = lookup_replace_object(sha1);
 	void *data = read_object(repl, type, size);
 	char *path;
+	const struct packed_git *p;
+
+	if (data) {
+		if (replacement)
+			*replacement = repl;
+		return data;
+	}
 
 	/* die if we replaced an object with one that does not exist */
-	if (!data && repl != sha1)
+	if (repl != sha1)
 		die("replacement %s not found for %s",
 		    sha1_to_hex(repl), sha1_to_hex(sha1));
 
-	/* legacy behavior is to die on corrupted objects */
-	if (!data) {
-		if (has_loose_object(repl)) {
-			path = sha1_file_name(sha1);
-			die("loose object %s (stored in %s) is corrupted", sha1_to_hex(repl), path);
-		}
-		if (has_packed_and_bad(repl)) {
-			path = sha1_pack_name(sha1);
-			die("packed object %s (stored in %s) is corrupted", sha1_to_hex(repl), path);
-		}
+	if (has_loose_object(repl)) {
+		path = sha1_file_name(sha1);
+		die("loose object %s (stored in %s) is corrupt",
+		    sha1_to_hex(repl), path);
 	}
 
-	if (replacement)
-		*replacement = repl;
+	if ((p = has_packed_and_bad(repl)) != NULL)
+		die("packed object %s (stored in %s) is corrupt",
+		    sha1_to_hex(repl), p->pack_name);
 
-	return data;
+	return NULL;
 }
 
 void *read_object_with_reference(const unsigned char *sha1,