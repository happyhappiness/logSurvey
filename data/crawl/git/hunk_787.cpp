 				      const char *path,
 				      unsigned flags)
 {
-	const char *sub_git_dir, *v;
-	char *real_sub_git_dir = NULL, *real_common_git_dir = NULL;
+	int err_code;
+	const char *sub_git_dir;
 	struct strbuf gitdir = STRBUF_INIT;
-
 	strbuf_addf(&gitdir, "%s/.git", path);
-	sub_git_dir = resolve_gitdir(gitdir.buf);
+	sub_git_dir = resolve_gitdir_gently(gitdir.buf, &err_code);
 
 	/* Not populated? */
-	if (!sub_git_dir)
-		goto out;
+	if (!sub_git_dir) {
+		char *real_new_git_dir;
+		const char *new_git_dir;
+		const struct submodule *sub;
+
+		if (err_code == READ_GITFILE_ERR_STAT_FAILED) {
+			/* unpopulated as expected */
+			strbuf_release(&gitdir);
+			return;
+		}
+
+		if (err_code != READ_GITFILE_ERR_NOT_A_REPO)
+			/* We don't know what broke here. */
+			read_gitfile_error_die(err_code, path, NULL);
+
+		/*
+		* Maybe populated, but no git directory was found?
+		* This can happen if the superproject is a submodule
+		* itself and was just absorbed. The absorption of the
+		* superproject did not rewrite the git file links yet,
+		* fix it now.
+		*/
+		sub = submodule_from_path(null_sha1, path);
+		if (!sub)
+			die(_("could not lookup name for submodule '%s'"), path);
+		new_git_dir = git_path("modules/%s", sub->name);
+		if (safe_create_leading_directories_const(new_git_dir) < 0)
+			die(_("could not create directory '%s'"), new_git_dir);
+		real_new_git_dir = real_pathdup(new_git_dir);
+		connect_work_tree_and_git_dir(path, real_new_git_dir);
+
+		free(real_new_git_dir);
+	} else {
+		/* Is it already absorbed into the superprojects git dir? */
+		char *real_sub_git_dir = real_pathdup(sub_git_dir);
+		char *real_common_git_dir = real_pathdup(get_git_common_dir());
 
-	/* Is it already absorbed into the superprojects git dir? */
-	real_sub_git_dir = real_pathdup(sub_git_dir);
-	real_common_git_dir = real_pathdup(get_git_common_dir());
-	if (!skip_prefix(real_sub_git_dir, real_common_git_dir, &v))
-		relocate_single_git_dir_into_superproject(prefix, path);
+		if (!starts_with(real_sub_git_dir, real_common_git_dir))
+			relocate_single_git_dir_into_superproject(prefix, path);
+
+		free(real_sub_git_dir);
+		free(real_common_git_dir);
+	}
+	strbuf_release(&gitdir);
 
 	if (flags & ABSORB_GITDIR_RECURSE_SUBMODULES) {
 		struct child_process cp = CHILD_PROCESS_INIT;
