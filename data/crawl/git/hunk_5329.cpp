 	 *   etc.
 	 */
 	offset = len = strlen(cwd);
+	one_filesystem = git_env_bool("GIT_ONE_FILESYSTEM", 0);
+	if (one_filesystem) {
+		if (stat(".", &buf))
+			die_errno("failed to stat '.'");
+		current_device = buf.st_dev;
+	}
 	for (;;) {
 		gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
 		if (gitfile_dir) {
