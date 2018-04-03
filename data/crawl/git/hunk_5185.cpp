 	commit = NULL;
 	if (ref_list->verbose || ref_list->with_commit || merge_filter != NO_FILTER) {
 		commit = lookup_commit_reference_gently(sha1, 1);
-		if (!commit)
-			return error("branch '%s' does not point at a commit", refname);
+		if (!commit) {
+			cb->ret = error("branch '%s' does not point at a commit", refname);
+			return cb->ret;
+		}
 
 		/* Filter with with_commit if specified */
 		if (!is_descendant_of(commit, ref_list->with_commit))
