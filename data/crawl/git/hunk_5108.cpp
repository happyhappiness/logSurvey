 	return retval;
 }
 
+static int cwd_contains_git_dir(const char **gitfile_dirp)
+{
+	const char *gitfile_dir = read_gitfile_gently(DEFAULT_GIT_DIR_ENVIRONMENT);
+	*gitfile_dirp = gitfile_dir;
+	if (gitfile_dir) {
+		if (set_git_dir(gitfile_dir))
+			die("Repository setup failed");
+		return 1;
+	}
+	return is_git_directory(DEFAULT_GIT_DIR_ENVIRONMENT);
+}
+
 /*
  * We cannot decide in this function whether we are in the work tree or
  * not, since the config can only be read _after_ this function was called.
