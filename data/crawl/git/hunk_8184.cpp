   struct stat sb;
   return stat(f, &sb) == 0;
 }
+
+/*
+ * get_relative_cwd() gets the prefix of the current working directory
+ * relative to 'dir'.  If we are not inside 'dir', it returns NULL.
+ * As a convenience, it also returns NULL if 'dir' is already NULL.
+ */
+char *get_relative_cwd(char *buffer, int size, const char *dir)
+{
+	char *cwd = buffer;
+
+	/*
+	 * a lazy caller can pass a NULL returned from get_git_work_tree()
+	 * and rely on this function to return NULL.
+	 */
+	if (!dir)
+		return NULL;
+	if (!getcwd(buffer, size))
+		die("can't find the current directory: %s", strerror(errno));
+
+	if (!is_absolute_path(dir))
+		dir = make_absolute_path(dir);
+
+	while (*dir && *dir == *cwd) {
+		dir++;
+		cwd++;
+	}
+	if (*dir)
+		return NULL;
+	if (*cwd == '/')
+		return cwd + 1;
+	return cwd;
+}
+
+int is_inside_dir(const char *dir)
+{
+	char buffer[PATH_MAX];
+	return get_relative_cwd(buffer, sizeof(buffer), dir) != NULL;
+}
