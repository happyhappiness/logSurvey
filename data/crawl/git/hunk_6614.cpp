 
 	if (interactive) {
 		interactive_add(argc, argv, prefix);
-		if (read_cache() < 0)
+		if (read_cache_preload(NULL) < 0)
 			die("index file corrupt");
 		commit_style = COMMIT_AS_IS;
 		return get_index_file();
 	}
 
-	if (read_cache() < 0)
-		die("index file corrupt");
-
 	if (*argv)
 		pathspec = get_pathspec(prefix, argv);
 
+	if (read_cache_preload(pathspec) < 0)
+		die("index file corrupt");
+
 	/*
 	 * Non partial, non as-is commit.
 	 *
