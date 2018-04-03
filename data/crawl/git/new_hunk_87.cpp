	if (offset >= 0) {	/* cwd inside worktree? */
		set_git_dir(real_path(gitdirenv));
		if (chdir(worktree))
			die_errno(_("cannot chdir to '%s'"), worktree);
		strbuf_addch(cwd, '/');
		free(gitfile);
		return cwd->buf + offset;
