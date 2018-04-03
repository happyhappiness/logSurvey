		/* No arguments -- use default remote */
		remote = remote_get(NULL);
		result = fetch_one(remote, argc, argv);
	} else {
		/* Single remote or group */
		(void) add_remote_or_group(argv[0], &list);
