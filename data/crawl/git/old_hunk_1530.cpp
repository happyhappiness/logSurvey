	if (!file_exists(sm_gitdir)) {
		if (safe_create_leading_directories_const(sm_gitdir) < 0)
			die(_("could not create directory '%s'"), sm_gitdir);
		if (clone_submodule(path, sm_gitdir, url, depth, &reference, quiet))
			die(_("clone of '%s' into submodule path '%s' failed"),
			    url, path);
