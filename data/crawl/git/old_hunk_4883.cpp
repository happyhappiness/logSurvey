			if (!getcwd(git_work_tree_cfg, PATH_MAX))
				die_errno ("Cannot access current working directory");
		}
		if (access(get_git_work_tree(), X_OK))
			die_errno ("Cannot access work tree '%s'",
				   get_git_work_tree());
	}

	set_git_dir(make_absolute_path(git_dir));

