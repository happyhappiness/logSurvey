	if (!submodule_uses_gitfile(path))
		return 0;

	argv_array_pushl(&cp.args, "status", "--porcelain", "-u",
				   "--ignore-submodules=none", NULL);
	prepare_submodule_repo_env(&cp.env_array);
	cp.git_cmd = 1;
	cp.no_stdin = 1;
	cp.out = -1;
	cp.dir = path;
	if (start_command(&cp))
		die(_("could not run 'git status --porcelain -u --ignore-submodules=none' in submodule %s"), path);

	len = strbuf_read(&buf, cp.out, 1024);
	if (len > 2)
		ok_to_remove = 0;
	close(cp.out);

	if (finish_command(&cp))
		die(_("'git status --porcelain -u --ignore-submodules=none' failed in submodule %s"), path);

	strbuf_release(&buf);
	return ok_to_remove;