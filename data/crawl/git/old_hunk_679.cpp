	cp.dir = path;
	if (start_command(&cp)) {
		if (flags & SUBMODULE_REMOVAL_DIE_ON_ERROR)
			die(_("could not start 'git status in submodule '%s'"),
				path);
		ret = -1;
		goto out;
