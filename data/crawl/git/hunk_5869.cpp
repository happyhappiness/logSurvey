 
 	fp = fopen(git_path(commit_editmsg), "w");
 	if (fp == NULL)
-		die("could not open %s: %s",
-		    git_path(commit_editmsg), strerror(errno));
+		die_errno("could not open '%s'", git_path(commit_editmsg));
 
 	if (cleanup_mode != CLEANUP_NONE)
 		stripspace(&sb, 0);
