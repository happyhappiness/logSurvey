 
 	fp = fopen(git_path(commit_editmsg), "w");
 	if (fp == NULL)
-		die("could not open %s\n", git_path(commit_editmsg));
+		die("could not open %s", git_path(commit_editmsg));
 
 	stripspace(&sb, 0);
 
