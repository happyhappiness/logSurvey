	argv[path_list->nr] = NULL;

	if (prefix && chdir(prefix))
		die("Failed to chdir: %s", prefix);
	status = run_command_v_opt(argv, RUN_USING_SHELL);
	if (status)
		exit(status);
