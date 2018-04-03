 	return git_dir;
 }
 
+static int git_work_tree_initialized;
+
+/*
+ * Note.  This works only before you used a work tree.  This was added
+ * primarily to support git-clone to work in a new repository it just
+ * created, and is not meant to flip between different work trees.
+ */
+void set_git_work_tree(const char *new_work_tree)
+{
+	if (is_bare_repository_cfg >= 0)
+		die("cannot set work tree after initialization");
+	git_work_tree_initialized = 1;
+	free(work_tree);
+	work_tree = xstrdup(make_absolute_path(new_work_tree));
+	is_bare_repository_cfg = 0;
+}
+
 const char *get_git_work_tree(void)
 {
-	static int initialized = 0;
-	if (!initialized) {
+	if (!git_work_tree_initialized) {
 		work_tree = getenv(GIT_WORK_TREE_ENVIRONMENT);
 		/* core.bare = true overrides implicit and config work tree */
 		if (!work_tree && is_bare_repository_cfg < 1) {
