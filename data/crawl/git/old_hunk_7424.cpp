	struct cmd_reflog_expire_cb cb;
	int i, status = 0;

	if (argc < 2)
		return error("Nothing to delete?");

	memset(&cb, 0, sizeof(cb));

	for (i = 1; i < argc; i++) {
		const char *spec = strstr(argv[i], "@{");
		unsigned char sha1[20];
		char *ep, *ref;