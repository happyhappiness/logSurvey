		else {
			char *core_worktree;
			if (chdir(gitdirenv))
				die_errno("Could not chdir to '%s'", gitdirenv);
			if (chdir(git_work_tree_cfg))
				die_errno("Could not chdir to '%s'", git_work_tree_cfg);
			core_worktree = xgetcwd();
			if (chdir(cwd->buf))
				die_errno("Could not come back to cwd");
			set_git_work_tree(core_worktree);
			free(core_worktree);
		}
