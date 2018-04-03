 	return retval;
 }
 
-static int cwd_contains_git_dir(const char **gitfile_dirp)
+static const char *setup_discovered_git_dir(const char *gitdir,
+					    char *cwd, int offset, int len,
+					    int *nongit_ok)
 {
-	const char *gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
-	*gitfile_dirp = gitfile_dir;
-	if (gitfile_dir) {
-		if (set_git_dir(gitfile_dir))
-			die("Repository setup failed");
-		return 1;
-	}
-	if (is_git_directory(DEFAULT_GIT_DIR_ENVIRONMENT)) {
-		*gitfile_dirp = DEFAULT_GIT_DIR_ENVIRONMENT;
-		return 1;
-	}
-	return 0;
-}
+	if (check_repository_format_gently(gitdir, nongit_ok))
+		return NULL;
 
-static const char *setup_discovered_git_dir(const char *work_tree_env,
-					    const char *gitdir,
-					    int offset, int len,
-					    char *cwd, int *nongit_ok)
-{
-	int root_len;
-	char *work_tree;
+	/* #16.2, #17.2, #20.2, #21.2, #24, #25, #28, #29 (see t1510) */
+	if (is_bare_repository_cfg > 0) {
+		set_git_dir(offset == len ? gitdir : make_absolute_path(gitdir));
+		if (chdir(cwd))
+			die_errno("Could not come back to cwd");
+		return NULL;
+	}
 
+	/* #0, #1, #5, #8, #9, #12, #13 */
+	set_git_work_tree(".");
+	if (strcmp(gitdir, DEFAULT_GIT_DIR_ENVIRONMENT))
+		set_git_dir(gitdir);
 	inside_git_dir = 0;
-	if (!work_tree_env)
-		inside_work_tree = 1;
-	root_len = offset_1st_component(cwd);
-	work_tree = xstrndup(cwd, offset > root_len ? offset : root_len);
-	set_git_work_tree(work_tree);
-	free(work_tree);
-	if (check_repository_format_gently(gitdir, nongit_ok))
-		return NULL;
+	inside_work_tree = 1;
 	if (offset == len)
 		return NULL;
 
