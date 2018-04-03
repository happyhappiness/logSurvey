 		if (!reflog_msg)
 			reflog_msg = "commit (merge)";
 		pptr = commit_list_append(current_head, pptr);
-		fp = fopen(git_path_merge_head(), "r");
-		if (fp == NULL)
-			die_errno(_("could not open '%s' for reading"),
-				  git_path_merge_head());
+		fp = xfopen(git_path_merge_head(), "r");
 		while (strbuf_getline_lf(&m, fp) != EOF) {
 			struct commit *parent;
 
