 
 int is_inside_git_dir(void)
 {
-	if (inside_git_dir < 0) {
-		char buffer[1024];
-
-		if (is_bare_repository())
-			return (inside_git_dir = 1);
-		if (getcwd(buffer, sizeof(buffer))) {
-			const char *git_dir = get_git_dir(), *cwd = buffer;
-			while (*git_dir && *git_dir == *cwd) {
-				git_dir++;
-				cwd++;
-			}
-			inside_git_dir = !*git_dir;
-		} else
-			inside_git_dir = 0;
+	if (inside_git_dir >= 0)
+		return inside_git_dir;
+	die("BUG: is_inside_git_dir called before setup_git_directory");
+}
+
+static int inside_work_tree = -1;
+
+int is_inside_work_tree(void)
+{
+	if (inside_git_dir >= 0)
+		return inside_work_tree;
+	die("BUG: is_inside_work_tree called before setup_git_directory");
+}
+
+static char *gitworktree_config;
+
+static int git_setup_config(const char *var, const char *value)
+{
+	if (!strcmp(var, "core.worktree")) {
+		if (gitworktree_config)
+			strlcpy(gitworktree_config, value, PATH_MAX);
+		return 0;
 	}
-	return inside_git_dir;
+	return git_default_config(var, value);
 }
 
 const char *setup_git_directory_gently(int *nongit_ok)
 {
 	static char cwd[PATH_MAX+1];
-	const char *gitdirenv;
-	int len, offset;
+	char worktree[PATH_MAX+1], gitdir[PATH_MAX+1];
+	const char *gitdirenv, *gitworktree;
+	int wt_rel_gitdir = 0;
 
-	/*
-	 * If GIT_DIR is set explicitly, we're not going
-	 * to do any discovery, but we still do repository
-	 * validation.
-	 */
 	gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
-	if (gitdirenv) {
-		if (PATH_MAX - 40 < strlen(gitdirenv))
-			die("'$%s' too big", GIT_DIR_ENVIRONMENT);
-		if (is_git_directory(gitdirenv))
+	if (!gitdirenv) {
+		int len, offset;
+
+		if (!getcwd(cwd, sizeof(cwd)-1) || cwd[0] != '/')
+			die("Unable to read current working directory");
+
+		offset = len = strlen(cwd);
+		for (;;) {
+			if (is_git_directory(".git"))
+				break;
+			if (offset == 0) {
+				offset = -1;
+				break;
+			}
+			chdir("..");
+			while (cwd[--offset] != '/')
+				; /* do nothing */
+		}
+
+		if (offset >= 0) {
+			inside_work_tree = 1;
+			git_config(git_default_config);
+			if (offset == len) {
+				inside_git_dir = 0;
+				return NULL;
+			}
+
+			cwd[len++] = '/';
+			cwd[len] = '\0';
+			inside_git_dir = !prefixcmp(cwd + offset + 1, ".git/");
+			return cwd + offset + 1;
+		}
+
+		if (chdir(cwd))
+			die("Cannot come back to cwd");
+		if (!is_git_directory(".")) {
+			if (nongit_ok) {
+				*nongit_ok = 1;
+				return NULL;
+			}
+			die("Not a git repository");
+		}
+		setenv(GIT_DIR_ENVIRONMENT, cwd, 1);
+	}
+
+	if (PATH_MAX - 40 < strlen(gitdirenv)) {
+		if (nongit_ok) {
+			*nongit_ok = 1;
 			return NULL;
+		}
+		die("$%s too big", GIT_DIR_ENVIRONMENT);
+	}
+	if (!is_git_directory(gitdirenv)) {
 		if (nongit_ok) {
 			*nongit_ok = 1;
 			return NULL;
