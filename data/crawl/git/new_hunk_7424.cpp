	struct cmd_reflog_expire_cb cb;
	int i, status = 0;

	memset(&cb, 0, sizeof(cb));

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (!strcmp(arg, "--dry-run") || !strcmp(arg, "-n"))
			cb.dry_run = 1;
		else if (!strcmp(arg, "--verbose"))
			cb.verbose = 1;
		else if (!strcmp(arg, "--")) {
			i++;
			break;
		}
		else if (arg[0] == '-')
			usage(reflog_delete_usage);
		else
			break;
	}

	if (argc - i < 1)
		return error("Nothing to delete?");

	for ( ; i < argc; i++) {
		const char *spec = strstr(argv[i], "@{");
		unsigned char sha1[20];
		char *ep, *ref;