 	else if (in_merge)
 		hook_arg1 = "merge";
 
+	if (squash_message) {
+		/*
+		 * If squash_commit was used for the commit subject,
+		 * then we're possibly hijacking other commit log options.
+		 * Reset the hook args to tell the real story.
+		 */
+		hook_arg1 = "message";
+		hook_arg2 = "";
+	}
+
 	fp = fopen(git_path(commit_editmsg), "w");
 	if (fp == NULL)
 		die_errno("could not open '%s'", git_path(commit_editmsg));
