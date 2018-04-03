 
 	setenv(CONFIG_ENVIRONMENT, xstrdup(mkpath("%s/config", git_dir)), 1);
 
+	if (safe_create_leading_directories_const(git_dir) < 0)
+		die("could not create leading directories of '%s'", git_dir);
 	set_git_dir(make_absolute_path(git_dir));
 
 	fprintf(stderr, "Initialize %s\n", git_dir);
