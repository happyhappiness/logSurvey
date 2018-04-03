		strbuf_reset(&sb);
	}

	/* Connect module worktree and git dir */
	connect_work_tree_and_git_dir(path, sm_gitdir);

	p = git_pathdup_submodule(path, "config");
	if (!p)
		die(_("could not get submodule directory for '%s'"), path);

	/* setup alternateLocation and alternateErrorStrategy in the cloned submodule if needed */
	git_config_get_string("submodule.alternateLocation", &sm_alternate);
