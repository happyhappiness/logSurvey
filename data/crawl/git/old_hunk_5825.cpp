		if (!git_work_tree_cfg) {
			git_work_tree_cfg = xcalloc(PATH_MAX, 1);
			if (!getcwd(git_work_tree_cfg, PATH_MAX))
				die ("Cannot access current working directory.");
		}
		if (access(get_git_work_tree(), X_OK))
			die ("Cannot access work tree '%s'",
			     get_git_work_tree());
	}

	set_git_dir(make_absolute_path(git_dir));
