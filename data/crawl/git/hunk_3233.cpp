 	 */
 	strbuf_addstr(&dirname, refname + dirname.len);
 	strbuf_addch(&dirname, '/');
-	pos = search_ref_dir(dir, dirname.buf, dirname.len);
 
-	if (pos >= 0) {
+	if (dir) {
+		pos = search_ref_dir(dir, dirname.buf, dirname.len);
+
+		if (pos >= 0) {
+			/*
+			 * We found a directory named "$refname/"
+			 * (e.g., "refs/foo/bar/"). It is a problem
+			 * iff it contains any ref that is not in
+			 * "skip".
+			 */
+			struct nonmatching_ref_data data;
+
+			data.skip = skip;
+			data.conflicting_refname = NULL;
+			dir = get_ref_dir(dir->entries[pos]);
+			sort_ref_dir(dir);
+			if (do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data)) {
+				error("'%s' exists; cannot create '%s'",
+				      data.conflicting_refname, refname);
+				goto cleanup;
+			}
+		}
+	}
+
+	if (extras) {
 		/*
-		 * We found a directory named "$refname/" (e.g.,
-		 * "refs/foo/bar/"). It is a problem iff it contains
-		 * any ref that is not in "skip".
+		 * Check for entries in extras that start with
+		 * "$refname/". We do that by looking for the place
+		 * where "$refname/" would be inserted in extras. If
+		 * there is an entry at that position that starts with
+		 * "$refname/" and is not in skip, then we have a
+		 * conflict.
 		 */
-		struct nonmatching_ref_data data;
-		struct ref_entry *entry = dir->entries[pos];
-
-		dir = get_ref_dir(entry);
-		data.skip = skip;
-		sort_ref_dir(dir);
-		if (!do_for_each_entry_in_dir(dir, 0, nonmatching_ref_fn, &data)) {
-			ret = 1;
-			goto cleanup;
-		}
+		for (pos = string_list_find_insert_index(extras, dirname.buf, 0);
+		     pos < extras->nr; pos++) {
+			const char *extra_refname = extras->items[pos].string;
 
-		error("'%s' exists; cannot create '%s'",
-		      data.conflicting_refname, refname);
-		goto cleanup;
+			if (!starts_with(extra_refname, dirname.buf))
+				break;
+
+			if (!skip || !string_list_has_string(skip, extra_refname)) {
+				error("cannot process '%s' and '%s' at the same time",
+				      refname, extra_refname);
+				goto cleanup;
+			}
+		}
 	}
 
+	/* No conflicts were found */
 	ret = 1;
 
 cleanup:
