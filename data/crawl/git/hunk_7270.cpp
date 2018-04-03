 
 	/*
 	 * Test in the following order (relative to the cwd):
+	 * - .git (file containing "gitdir: <path>")
 	 * - .git/
 	 * - ./ (bare)
+	 * - ../.git
 	 * - ../.git/
 	 * - ../ (bare)
 	 * - ../../.git/
 	 *   etc.
 	 */
 	offset = len = strlen(cwd);
 	for (;;) {
+		gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
+		if (gitfile_dir) {
+			if (set_git_dir(gitfile_dir))
+				die("Repository setup failed");
+			break;
+		}
 		if (is_git_directory(DEFAULT_GIT_DIR_ENVIRONMENT))
 			break;
 		if (is_git_directory(".")) {
