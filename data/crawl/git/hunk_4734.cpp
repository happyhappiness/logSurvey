 		die(_("could not create leading directories of '%s'"), git_dir);
 	set_git_dir(make_absolute_path(git_dir));
 
-	if (0 <= option_verbosity)
-		printf("Cloning into %s%s...\n",
-		       option_bare ? "bare repository " : "", dir);
+	if (0 <= option_verbosity) {
+		if (option_bare)
+			printf("Cloning into bare repository %s...\n", dir);
+		else
+			printf("Cloning into %s...\n", dir);
+	}
 	init_db(option_template, INIT_DB_QUIET);
 
 	/*