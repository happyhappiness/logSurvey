 		dir = xstrdup(argv[1]);
 	else
 		dir = guess_dir_name(repo_name, is_bundle, option_bare);
+	strip_trailing_slashes(dir);
 
 	if (!stat(dir, &buf))
 		die("destination directory '%s' already exists.", dir);
