 	const char **pathspec = NULL;
 
 	if (interactive) {
-		interactive_add(argc, argv, prefix);
+		if (interactive_add(argc, argv, prefix) != 0)
+			die("interactive add failed");
 		if (read_cache_preload(NULL) < 0)
 			die("index file corrupt");
 		commit_style = COMMIT_AS_IS;
