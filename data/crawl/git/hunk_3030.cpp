 	find_conflict(&conflict);
 
 	/*
-	 * MERGE_RR records paths with conflicts immediately after merge
-	 * failed.  Some of the conflicted paths might have been hand resolved
-	 * in the working tree since then, but the initial run would catch all
-	 * and register their preimages.
+	 * MERGE_RR records paths with conflicts immediately after
+	 * merge failed.  Some of the conflicted paths might have been
+	 * hand resolved in the working tree since then, but the
+	 * initial run would catch all and register their preimages.
 	 */
-
 	for (i = 0; i < conflict.nr; i++) {
 		const char *path = conflict.items[i].string;
 		if (!string_list_has_string(rr, path)) {
 			unsigned char sha1[20];
 			char *hex;
 			int ret;
+
+			/*
+			 * Ask handle_file() to scan and assign a
+			 * conflict ID.  No need to write anything out
+			 * yet.
+			 */
 			ret = handle_file(path, sha1, NULL);
 			if (ret < 1)
 				continue;
 			hex = xstrdup(sha1_to_hex(sha1));
 			string_list_insert(rr, path)->util = hex;
+
+			/*
+			 * If the directory does not exist, create
+			 * it.  mkdir_in_gitdir() will fail with
+			 * EEXIST if there already is one.
+			 *
+			 * NEEDSWORK: make sure "gc" does not remove
+			 * preimage without removing the directory.
+			 */
 			if (mkdir_in_gitdir(git_path("rr-cache/%s", hex)))
 				continue;
+
+			/*
+			 * We are the first to encounter this
+			 * conflict.  Ask handle_file() to write the
+			 * normalized contents to the "preimage" file.
+			 */
 			handle_file(path, NULL, rerere_path(hex, "preimage"));
 			fprintf(stderr, "Recorded preimage for '%s'\n", path);
 		}
 	}
 
 	/*
-	 * Now some of the paths that had conflicts earlier might have been
-	 * hand resolved.  Others may be similar to a conflict already that
-	 * was resolved before.
+	 * Some of the paths that had conflicts earlier might have
+	 * been resolved by the user.  Others may be similar to a
+	 * conflict already that was resolved before.
 	 */
-
 	for (i = 0; i < rr->nr; i++) {
 		int ret;
 		const char *path = rr->items[i].string;
 		const char *name = (const char *)rr->items[i].util;
 
+		/* Is there a recorded resolution we could attempt to apply? */
 		if (has_rerere_resolution(name)) {
 			if (merge(name, path))
 				continue;
