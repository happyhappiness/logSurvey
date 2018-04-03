
	remote_group.list = &list;
	for (i = 1; i < argc; i++) {
		remote_group.name = argv[i];
		result = git_config(get_remote_group, NULL);
	}

	if (!result && !list.nr  && argc == 2 && !strcmp(argv[1], "default"))