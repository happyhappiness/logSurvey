 		OPT_END()
 	};
 
-	/*
-	 * NEEDSWORK: Once all the features of git-am.sh have been
-	 * re-implemented in builtin/am.c, this preamble can be removed.
-	 */
-	if (!getenv("_GIT_USE_BUILTIN_AM")) {
-		const char *path = mkpath("%s/git-am", git_exec_path());
-
-		if (sane_execvp(path, (char **)argv) < 0)
-			die_errno("could not exec %s", path);
-	} else {
-		prefix = setup_git_directory();
-		trace_repo_setup(prefix);
-		setup_work_tree();
-	}
-
 	git_config(git_default_config, NULL);
 
 	am_state_init(&state, git_path("rebase-apply"));
