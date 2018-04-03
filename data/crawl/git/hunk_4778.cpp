 		hook_arg2 = "";
 	}
 
-	fp = fopen(git_path(commit_editmsg), "w");
-	if (fp == NULL)
+	s->fp = fopen(git_path(commit_editmsg), "w");
+	if (s->fp == NULL)
 		die_errno("could not open '%s'", git_path(commit_editmsg));
 
 	if (cleanup_mode != CLEANUP_NONE)
