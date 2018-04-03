 		die("could not create leading directories of '%s'", git_dir);
 	set_git_dir(make_absolute_path(git_dir));
 
-	init_db(option_template, (option_verbosity < 0) ? INIT_DB_QUIET : 0);
+	if (0 <= option_verbosity)
+		printf("Cloning into %s...\n", get_git_dir());
+	init_db(option_template, INIT_DB_QUIET);
 
 	/*
 	 * At this point, the config exists, so we do not need the
