 	struct commit **rev;
 	int i = 0, rev_nr = 0;
 
-	base = lookup_commit_reference_by_name(base_commit);
-	if (!base)
-		die(_("Unknown commit %s"), base_commit);
+	if (!strcmp(base_commit, "auto")) {
+		struct branch *curr_branch = branch_get(NULL);
+		const char *upstream = branch_get_upstream(curr_branch, NULL);
+		if (upstream) {
+			struct commit_list *base_list;
+			struct commit *commit;
+			unsigned char sha1[20];
+
+			if (get_sha1(upstream, sha1))
+				die(_("Failed to resolve '%s' as a valid ref."), upstream);
+			commit = lookup_commit_or_die(sha1, "upstream base");
+			base_list = get_merge_bases_many(commit, total, list);
+			/* There should be one and only one merge base. */
+			if (!base_list || base_list->next)
+				die(_("Could not find exact merge base."));
+			base = base_list->item;
+			free_commit_list(base_list);
+		} else {
+			die(_("Failed to get upstream, if you want to record base commit automatically,\n"
+			      "please use git branch --set-upstream-to to track a remote branch.\n"
+			      "Or you could specify base commit by --base=<base-commit-id> manually."));
+		}
+	} else {
+		base = lookup_commit_reference_by_name(base_commit);
+		if (!base)
+			die(_("Unknown commit %s"), base_commit);
+	}
 
 	ALLOC_ARRAY(rev, total);
 	for (i = 0; i < total; i++)
