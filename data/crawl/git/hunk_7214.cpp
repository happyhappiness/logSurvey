 		    GIT_WORK_TREE_ENVIRONMENT,
 		    GIT_DIR_ENVIRONMENT);
 
-	guess_repository_type(git_dir);
-
-	if (is_bare_repository_cfg <= 0) {
-		git_work_tree_cfg = xcalloc(PATH_MAX, 1);
-		if (!getcwd(git_work_tree_cfg, PATH_MAX))
-			die ("Cannot access current working directory.");
-		if (access(get_git_work_tree(), X_OK))
-			die ("Cannot access work tree '%s'",
-			     get_git_work_tree());
-	}
-
 	/*
 	 * Set up the default .git directory contents
 	 */
-	git_dir = getenv(GIT_DIR_ENVIRONMENT);
 	if (!git_dir)
 		git_dir = DEFAULT_GIT_DIR_ENVIRONMENT;
-	safe_create_dir(git_dir, 0);
-
-	/* Check to see if the repository version is right.
-	 * Note that a newly created repository does not have
-	 * config file, so this will not fail.  What we are catching
-	 * is an attempt to reinitialize new repository with an old tool.
-	 */
-	check_repository_format();
-
-	reinit = create_default_files(git_dir, template_dir);
-
-	/*
-	 * And set up the object store.
-	 */
-	sha1_dir = get_object_directory();
-	len = strlen(sha1_dir);
-	path = xmalloc(len + 40);
-	memcpy(path, sha1_dir, len);
-
-	safe_create_dir(sha1_dir, 1);
-	strcpy(path+len, "/pack");
-	safe_create_dir(path, 1);
-	strcpy(path+len, "/info");
-	safe_create_dir(path, 1);
 
-	if (shared_repository) {
-		char buf[10];
-		/* We do not spell "group" and such, so that
-		 * the configuration can be read by older version
-		 * of git. Note, we use octal numbers for new share modes,
-		 * and compatibility values for PERM_GROUP and
-		 * PERM_EVERYBODY.
-		 */
-		if (shared_repository == PERM_GROUP)
-			sprintf(buf, "%d", OLD_PERM_GROUP);
-		else if (shared_repository == PERM_EVERYBODY)
-			sprintf(buf, "%d", OLD_PERM_EVERYBODY);
-		else
-			sprintf(buf, "0%o", shared_repository);
-		git_config_set("core.sharedrepository", buf);
-		git_config_set("receive.denyNonFastforwards", "true");
+	if (is_bare_repository_cfg < 0)
+		is_bare_repository_cfg = guess_repository_type(git_dir);
+
+	if (!is_bare_repository_cfg) {
+		if (git_dir) {
+			const char *git_dir_parent = strrchr(git_dir, '/');
+			if (git_dir_parent) {
+				char *rel = xstrndup(git_dir, git_dir_parent - git_dir);
+				git_work_tree_cfg = xstrdup(make_absolute_path(rel));
+				free(rel);
+			}
+		}
+		if (!git_work_tree_cfg) {
+			git_work_tree_cfg = xcalloc(PATH_MAX, 1);
+			if (!getcwd(git_work_tree_cfg, PATH_MAX))
+				die ("Cannot access current working directory.");
+		}
+		if (access(get_git_work_tree(), X_OK))
+			die ("Cannot access work tree '%s'",
+			     get_git_work_tree());
 	}
 
-	if (!quiet)
-		printf("%s%s Git repository in %s/\n",
-		       reinit ? "Reinitialized existing" : "Initialized empty",
-		       shared_repository ? " shared" : "",
-		       git_dir);
+	set_git_dir(make_absolute_path(git_dir));
 
-	return 0;
+	return init_db(template_dir, flags);
 }
