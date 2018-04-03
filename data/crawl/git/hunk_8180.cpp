 	return 1;
 }
 
-static int inside_git_dir = -1;
-
 int is_inside_git_dir(void)
 {
-	if (inside_git_dir >= 0)
-		return inside_git_dir;
-	die("BUG: is_inside_git_dir called before setup_git_directory");
+	if (inside_git_dir < 0)
+		inside_git_dir = is_inside_dir(get_git_dir());
+	return inside_git_dir;
 }
 
-static int inside_work_tree = -1;
-
 int is_inside_work_tree(void)
 {
-	if (inside_git_dir >= 0)
-		return inside_work_tree;
-	die("BUG: is_inside_work_tree called before setup_git_directory");
+	if (inside_work_tree < 0)
+		inside_work_tree = is_inside_dir(get_git_work_tree());
+	return inside_work_tree;
 }
 
-static char *gitworktree_config;
-
-static int git_setup_config(const char *var, const char *value)
+/*
+ * If no worktree was given, and we are outside of a default work tree,
+ * now is the time to set it.
+ *
+ * In other words, if the user calls git with something like
+ *
+ *	git --git-dir=/some/where/else/.git bla
+ *
+ * default to /some/where/else as working directory; if the specified
+ * git-dir does not end in "/.git", the cwd is used as working directory.
+ */
+const char *set_work_tree(const char *dir)
 {
-	if (!strcmp(var, "core.worktree")) {
-		if (gitworktree_config)
-			strlcpy(gitworktree_config, value, PATH_MAX);
-		return 0;
+	char dir_buffer[PATH_MAX];
+	static char buffer[PATH_MAX + 1], *rel = NULL;
+	int len, postfix_len = strlen(DEFAULT_GIT_DIR_ENVIRONMENT) + 1;
+
+	/* strip the variable 'dir' of the postfix "/.git" if it has it */
+	len = strlen(dir);
+	if (len > postfix_len && !strcmp(dir + len - postfix_len,
+				"/" DEFAULT_GIT_DIR_ENVIRONMENT)) {
+			strncpy(dir_buffer, dir, len - postfix_len);
+
+		/* are we inside the default work tree? */
+		rel = get_relative_cwd(buffer, sizeof(buffer), dir_buffer);
+	}
+	/* if rel is set, the cwd is _not_ the current working tree */
+	if (rel && *rel) {
+		if (!is_absolute_path(dir))
+			set_git_dir(make_absolute_path(dir));
+		dir = dir_buffer;
+		chdir(dir);
+		strcat(rel, "/");
+		inside_git_dir = 0;
+	} else {
+		rel = NULL;
+		dir = getcwd(buffer, sizeof(buffer));
 	}
-	return git_default_config(var, value);
+	git_work_tree_cfg = xstrdup(dir);
+	inside_work_tree = 1;
+
+	return rel;
 }
 
+/*
+ * We cannot decide in this function whether we are in the work tree or
+ * not, since the config can only be read _after_ this function was called.
+ */
 const char *setup_git_directory_gently(int *nongit_ok)
 {
+	const char *work_tree_env = getenv(GIT_WORK_TREE_ENVIRONMENT);
 	static char cwd[PATH_MAX+1];
-	char worktree[PATH_MAX+1], gitdir[PATH_MAX+1];
-	const char *gitdirenv, *gitworktree;
-	int wt_rel_gitdir = 0;
+	const char *gitdirenv;
+	int len, offset;
 
+	/*
+	 * If GIT_DIR is set explicitly, we're not going
+	 * to do any discovery, but we still do repository
+	 * validation.
+	 */
 	gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
-	if (!gitdirenv) {
-		int len, offset;
-
-		if (!getcwd(cwd, sizeof(cwd)-1))
-			die("Unable to read current working directory");
-
-		offset = len = strlen(cwd);
-		for (;;) {
-			if (is_git_directory(".git"))
-				break;
-			if (offset == 0) {
-				offset = -1;
-				break;
-			}
-			chdir("..");
-			while (cwd[--offset] != '/')
-				; /* do nothing */
-		}
-
-		if (offset >= 0) {
-			inside_work_tree = 1;
-			git_config(git_default_config);
-			if (offset == len) {
-				inside_git_dir = 0;
-				return NULL;
-			}
-
-			cwd[len++] = '/';
-			cwd[len] = '\0';
-			inside_git_dir = !prefixcmp(cwd + offset + 1, ".git/");
-			return cwd + offset + 1;
-		}
-
-		if (chdir(cwd))
-			die("Cannot come back to cwd");
-		if (!is_git_directory(".")) {
-			if (nongit_ok) {
-				*nongit_ok = 1;
-				return NULL;
-			}
-			die("Not a git repository");
-		}
-		setenv(GIT_DIR_ENVIRONMENT, cwd, 1);
-		gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
-		if (!gitdirenv)
-			die("getenv after setenv failed");
-	}
-
-	if (PATH_MAX - 40 < strlen(gitdirenv)) {
-		if (nongit_ok) {
-			*nongit_ok = 1;
+	if (gitdirenv) {
+		if (PATH_MAX - 40 < strlen(gitdirenv))
+			die("'$%s' too big", GIT_DIR_ENVIRONMENT);
+		if (is_git_directory(gitdirenv)) {
+			if (!work_tree_env)
+				return set_work_tree(gitdirenv);
 			return NULL;
 		}
-		die("$%s too big", GIT_DIR_ENVIRONMENT);
-	}
-	if (!is_git_directory(gitdirenv)) {
 		if (nongit_ok) {
 			*nongit_ok = 1;
 			return NULL;
