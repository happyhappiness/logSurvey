 
 	if (old_sha1) {
 		unsigned char actual_old_sha1[20];
-		read_ref(pseudoref, actual_old_sha1);
+
+		if (read_ref(pseudoref, actual_old_sha1))
+			die("could not read ref '%s'", pseudoref);
 		if (hashcmp(actual_old_sha1, old_sha1)) {
 			strbuf_addf(err, "Unexpected sha1 when writing %s", pseudoref);
 			rollback_lock_file(&lock);
