 			usage(init_db_usage);
 	}
 
-	git_work_tree = get_work_tree();
+	git_work_tree_cfg = xcalloc(PATH_MAX, 1);
+	if (!getcwd(git_work_tree_cfg, PATH_MAX))
+		die ("Cannot access current working directory.");
+	if (access(get_git_work_tree(), X_OK))
+		die ("Cannot access work tree '%s'", get_git_work_tree());
 
 	/*
 	 * Set up the default .git directory contents
