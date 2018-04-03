 	if ((kind & ref_list->kinds) == 0)
 		return 0;
 
+	if (mergefilter > -1) {
+		branch.item = lookup_commit_reference_gently(sha1, 1);
+		if (!branch.item)
+			die("Unable to lookup tip of branch %s", refname);
+		if (mergefilter == 0 && has_commit(head_sha1, &branch))
+			return 0;
+		if (mergefilter == 1 && !has_commit(head_sha1, &branch))
+			return 0;
+	}
+
 	/* Resize buffer */
 	if (ref_list->index >= ref_list->alloc) {
 		ref_list->alloc = alloc_nr(ref_list->alloc);
