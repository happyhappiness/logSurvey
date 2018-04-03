 	closedir(dir);
 }
 
-static int create_default_files(const char *git_dir, const char *template_path)
+/*
+ * Get the full path to the working tree specified in $GIT_WORK_TREE
+ * or NULL if no working tree is specified.
+ */
+static const char *get_work_tree(void)
+{
+	const char *git_work_tree;
+	char cwd[PATH_MAX];
+	static char worktree[PATH_MAX];
+
+	git_work_tree = getenv(GIT_WORK_TREE_ENVIRONMENT);
+	if (!git_work_tree)
+		return NULL;
+	if (!getcwd(cwd, sizeof(cwd)))
+		die("Unable to read current working directory");
+	if (chdir(git_work_tree))
+		die("Cannot change directory to specified working tree '%s'",
+			git_work_tree);
+	if (git_work_tree[0] != '/') {
+		if (!getcwd(worktree, sizeof(worktree)))
+			die("Unable to read current working directory");
+		git_work_tree = worktree;
+	}
+	if (chdir(cwd))
+		die("Cannot come back to cwd");
+	return git_work_tree;
+}
+
+static int create_default_files(const char *git_dir, const char *git_work_tree,
+	const char *template_path)
 {
 	unsigned len = strlen(git_dir);
 	static char path[PATH_MAX];
