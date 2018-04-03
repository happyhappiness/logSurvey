 	 * initial run would catch all and register their preimages.
 	 */
 	for (i = 0; i < conflict.nr; i++) {
+		unsigned char sha1[20];
+		char *hex;
+		int ret;
 		const char *path = conflict.items[i].string;
-		if (!string_list_has_string(rr, path)) {
-			unsigned char sha1[20];
-			char *hex;
-			int ret;
 
-			/*
-			 * Ask handle_file() to scan and assign a
-			 * conflict ID.  No need to write anything out
-			 * yet.
-			 */
-			ret = handle_file(path, sha1, NULL);
-			if (ret < 1)
-				continue;
-			hex = xstrdup(sha1_to_hex(sha1));
-			string_list_insert(rr, path)->util = hex;
+		if (string_list_has_string(rr, path))
+			continue;
 
-			/*
-			 * If the directory does not exist, create
-			 * it.  mkdir_in_gitdir() will fail with
-			 * EEXIST if there already is one.
-			 *
-			 * NEEDSWORK: make sure "gc" does not remove
-			 * preimage without removing the directory.
-			 */
-			if (mkdir_in_gitdir(git_path("rr-cache/%s", hex)))
-				continue;
+		/*
+		 * Ask handle_file() to scan and assign a
+		 * conflict ID.  No need to write anything out
+		 * yet.
+		 */
+		ret = handle_file(path, sha1, NULL);
+		if (ret < 1)
+			continue;
+		hex = xstrdup(sha1_to_hex(sha1));
+		string_list_insert(rr, path)->util = hex;
 
-			/*
-			 * We are the first to encounter this
-			 * conflict.  Ask handle_file() to write the
-			 * normalized contents to the "preimage" file.
-			 */
-			handle_file(path, NULL, rerere_path(hex, "preimage"));
-			fprintf(stderr, "Recorded preimage for '%s'\n", path);
-		}
+		/*
+		 * If the directory does not exist, create
+		 * it.  mkdir_in_gitdir() will fail with
+		 * EEXIST if there already is one.
+		 *
+		 * NEEDSWORK: make sure "gc" does not remove
+		 * preimage without removing the directory.
+		 */
+		if (mkdir_in_gitdir(git_path("rr-cache/%s", hex)))
+			continue;
+
+		/*
+		 * We are the first to encounter this
+		 * conflict.  Ask handle_file() to write the
+		 * normalized contents to the "preimage" file.
+		 */
+		handle_file(path, NULL, rerere_path(hex, "preimage"));
+		fprintf(stderr, "Recorded preimage for '%s'\n", path);
 	}
 
 	for (i = 0; i < rr->nr; i++)