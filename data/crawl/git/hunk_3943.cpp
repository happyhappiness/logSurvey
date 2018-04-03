 						PARSE_OPT_KEEP_DASHDASH);
 	pathspec = parse_args(argv, prefix, &rev);
 
-	if (get_sha1_committish(rev, sha1))
-		die(_("Failed to resolve '%s' as a valid ref."), rev);
-
-	/*
-	 * NOTE: As "git reset $treeish -- $path" should be usable on
-	 * any tree-ish, this is not strictly correct. We are not
-	 * moving the HEAD to any commit; we are merely resetting the
-	 * entries in the index to that of a treeish.
-	 */
-	commit = lookup_commit_reference(sha1);
-	if (!commit)
-		die(_("Could not parse object '%s'."), rev);
-	hashcpy(sha1, commit->object.sha1);
+	if (!pathspec) {
+		struct commit *commit;
+		if (get_sha1_committish(rev, sha1))
+			die(_("Failed to resolve '%s' as a valid revision."), rev);
+		commit = lookup_commit_reference(sha1);
+		if (!commit)
+			die(_("Could not parse object '%s'."), rev);
+		hashcpy(sha1, commit->object.sha1);
+	} else {
+		struct tree *tree;
+		if (get_sha1_treeish(rev, sha1))
+			die(_("Failed to resolve '%s' as a valid tree."), rev);
+		tree = parse_tree_indirect(sha1);
+		if (!tree)
+			die(_("Could not parse object '%s'."), rev);
+		hashcpy(sha1, tree->object.sha1);
+	}
 
 	if (patch_mode) {
 		if (reset_type != NONE)
