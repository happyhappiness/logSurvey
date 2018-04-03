 	const char *remote = curr_branch ? curr_branch->remote_name : NULL;
 
 	if (*refspecs) {
-		fprintf_ln(stderr, _("There are no candidates for merging among the refs that you just fetched."));
+		if (opt_rebase)
+			fprintf_ln(stderr, _("There is no candidate for rebasing against among the refs that you just fetched."));
+		else
+			fprintf_ln(stderr, _("There are no candidates for merging among the refs that you just fetched."));
 		fprintf_ln(stderr, _("Generally this means that you provided a wildcard refspec which had no\n"
 					"matches on the remote end."));
 	} else if (repo && curr_branch && (!remote || strcmp(repo, remote))) {
