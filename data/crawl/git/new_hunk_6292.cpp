
	remote_group.list = &list;
	for (i = 1; i < argc; i++) {
		int groups_found = 0;
		remote_group.name = argv[i];
		result = git_config(get_remote_group, &groups_found);
		if (!groups_found && (i != 1 || strcmp(argv[1], "default")))
			die("No such remote group: '%s'", argv[i]);
	}

	if (!result && !list.nr  && argc == 2 && !strcmp(argv[1], "default"))