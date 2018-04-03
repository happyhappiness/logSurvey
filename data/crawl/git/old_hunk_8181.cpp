
	if (!getcwd(cwd, sizeof(cwd)-1))
		die("Unable to read current working directory");
	if (chdir(gitdirenv)) {
		if (nongit_ok) {
			*nongit_ok = 1;
			return NULL;
		}
		die("Cannot change directory to $%s '%s'",
			GIT_DIR_ENVIRONMENT, gitdirenv);
	}
	if (!getcwd(gitdir, sizeof(gitdir)-1))
		die("Unable to read current working directory");
	if (chdir(cwd))
		die("Cannot come back to cwd");

	/*
	 * In case there is a work tree we may change the directory,
	 * therefore make GIT_DIR an absolute path.
	 */
	if (gitdirenv[0] != '/') {
		setenv(GIT_DIR_ENVIRONMENT, gitdir, 1);
		gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
		if (!gitdirenv)
			die("getenv after setenv failed");
		if (PATH_MAX - 40 < strlen(gitdirenv)) {
			if (nongit_ok) {
				*nongit_ok = 1;
				return NULL;
			}
			die("$%s too big after expansion to absolute path",
				GIT_DIR_ENVIRONMENT);
		}
	}

	strcat(cwd, "/");
	strcat(gitdir, "/");
	inside_git_dir = !prefixcmp(cwd, gitdir);

	gitworktree = getenv(GIT_WORK_TREE_ENVIRONMENT);
	if (!gitworktree) {
		gitworktree_config = worktree;
		worktree[0] = '\0';
	}
	git_config(git_setup_config);
	if (!gitworktree) {
		gitworktree_config = NULL;
		if (worktree[0])
			gitworktree = worktree;
		if (gitworktree && gitworktree[0] != '/')
			wt_rel_gitdir = 1;
	}

	if (wt_rel_gitdir && chdir(gitdirenv))
		die("Cannot change directory to $%s '%s'",
			GIT_DIR_ENVIRONMENT, gitdirenv);
	if (gitworktree && chdir(gitworktree)) {
		if (nongit_ok) {
			if (wt_rel_gitdir && chdir(cwd))
				die("Cannot come back to cwd");
			*nongit_ok = 1;
			return NULL;
		}
		if (wt_rel_gitdir)
			die("Cannot change directory to working tree '%s'"
				" from $%s", gitworktree, GIT_DIR_ENVIRONMENT);
		else
			die("Cannot change directory to working tree '%s'",
				gitworktree);
	}
	if (!getcwd(worktree, sizeof(worktree)-1))
		die("Unable to read current working directory");
	strcat(worktree, "/");
	inside_work_tree = !prefixcmp(cwd, worktree);

	if (gitworktree && inside_work_tree && !prefixcmp(worktree, gitdir) &&
	    strcmp(worktree, gitdir)) {
		inside_git_dir = 0;
	}

	if (!inside_work_tree) {
		if (chdir(cwd))
			die("Cannot come back to cwd");
		return NULL;
	}

	if (!strcmp(cwd, worktree))
		return NULL;
	return cwd+strlen(worktree);
}

int git_config_perm(const char *var, const char *value)
