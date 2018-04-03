 	if (nongit_ok)
 		*nongit_ok = 0;
 
+	if (!getcwd(cwd, sizeof(cwd)-1))
+		die_errno("Unable to read current working directory");
+	offset = len = strlen(cwd);
+
 	/*
 	 * If GIT_DIR is set explicitly, we're not going
 	 * to do any discovery, but we still do repository
 	 * validation.
 	 */
 	gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
 	if (gitdirenv)
-		return setup_explicit_git_dir(gitdirenv, work_tree_env, nongit_ok);
-
-	if (!getcwd(cwd, sizeof(cwd)-1))
-		die_errno("Unable to read current working directory");
+		return setup_explicit_git_dir(gitdirenv, cwd, len, nongit_ok);
 
 	ceil_offset = longest_ancestor_length(cwd, env_ceiling_dirs);
 	if (ceil_offset < 0 && has_dos_drive_prefix(cwd))
