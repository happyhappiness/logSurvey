		/* All arguments are assumed to be remotes or groups */
		for (i = 0; i < argc; i++)
			if (!add_remote_or_group(argv[i], &list))
				die("No such remote or remote group: %s", argv[i]);
		result = fetch_multiple(&list);
	} else {
		/* Single remote or group */
		(void) add_remote_or_group(argv[0], &list);
		if (list.nr > 1) {
			/* More than one remote */
			if (argc > 1)
				die("Fetching a group and specifying refspecs does not make sense");
			result = fetch_multiple(&list);
		} else {
			/* Zero or one remotes */