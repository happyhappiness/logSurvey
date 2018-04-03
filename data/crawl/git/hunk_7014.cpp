 	if ((kind & ref_list->kinds) == 0)
 		return 0;
 
-	if (mergefilter > -1) {
+	if (merge_filter != NO_FILTER) {
 		branch.item = lookup_commit_reference_gently(sha1, 1);
 		if (!branch.item)
 			die("Unable to lookup tip of branch %s", refname);
-		if (mergefilter == 0 && has_commit(head_sha1, &branch))
+		if (merge_filter == SHOW_NOT_MERGED &&
+		    has_commit(merge_filter_ref, &branch))
 			return 0;
-		if (mergefilter == 1 && !has_commit(head_sha1, &branch))
+		if (merge_filter == SHOW_MERGED &&
+		    !has_commit(merge_filter_ref, &branch))
 			return 0;
 	}
 
