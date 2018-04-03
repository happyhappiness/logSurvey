	}
	else if (actions == ACTION_EDIT) {
		check_argc(argc, 0, 0);
		git_config(git_default_config, NULL);
		launch_editor(config_exclusive_filename ?
			      config_exclusive_filename : git_path("config"),