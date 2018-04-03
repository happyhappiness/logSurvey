		if (offset != cwd->len && !is_absolute_path(gitdir))
			gitdir = to_free = real_pathdup(gitdir, 1);
		if (chdir(cwd->buf))
			die_errno(_("cannot come back to cwd"));
		ret = setup_explicit_git_dir(gitdir, cwd, repo_fmt, nongit_ok);
		free(to_free);
		return ret;
