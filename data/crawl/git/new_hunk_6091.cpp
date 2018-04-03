	}
	else if (actions == ACTION_EDIT) {
		check_argc(argc, 0, 0);
		if (!config_exclusive_filename && nongit)
			die("not in a git directory");
		git_config(git_default_config, NULL);
		launch_editor(config_exclusive_filename ?
			      config_exclusive_filename : git_path("config"),