	if (is_bare_repository_cfg > 0) {
		set_git_dir(offset == cwd->len ? gitdir : real_path(gitdir));
		if (chdir(cwd->buf))
			die_errno(_("cannot come back to cwd"));
		return NULL;
	}
