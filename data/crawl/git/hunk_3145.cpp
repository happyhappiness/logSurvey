 	if (!merge_heads.nr)
 		die_no_merge_candidates(repo, refspecs);
 
-	return run_merge();
+	if (is_null_sha1(orig_head)) {
+		if (merge_heads.nr > 1)
+			die(_("Cannot merge multiple branches into empty head."));
+		return pull_into_void(*merge_heads.sha1, curr_head);
+	} else
+		return run_merge();
 }