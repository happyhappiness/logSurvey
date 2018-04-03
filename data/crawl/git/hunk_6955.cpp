 		die("cannot do a partial commit during a merge.");
 
 	memset(&partial, 0, sizeof(partial));
-	partial.strdup_paths = 1;
+	partial.strdup_strings = 1;
 	if (list_paths(&partial, initial_commit ? NULL : "HEAD", prefix, pathspec))
 		exit(1);
 
