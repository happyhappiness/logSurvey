 	setup_path();
 
 	if (!enter_repo(dir, 0))
-		die("'%s': unable to chdir or not a git archive", dir);
+		die("'%s' does not appear to be a git repository", dir);
 
 	if (is_repository_shallow())
 		die("attempt to push into a shallow repository");