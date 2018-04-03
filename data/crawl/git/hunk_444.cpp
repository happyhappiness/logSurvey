 	packed_refs->cache->root->flag &= ~REF_INCOMPLETE;
 
 	f = fopen(packed_refs_file, "r");
-	if (!f)
-		return packed_refs;
+	if (!f) {
+		if (errno == ENOENT) {
+			/*
+			 * This is OK; it just means that no
+			 * "packed-refs" file has been written yet,
+			 * which is equivalent to it being empty.
+			 */
+			return packed_refs;
+		} else {
+			die_errno("couldn't read %s", packed_refs_file);
+		}
+	}
 
 	stat_validity_update(&packed_refs->validity, fileno(f));
 