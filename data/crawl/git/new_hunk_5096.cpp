	char *index_name_buf = NULL, *keep_name_buf = NULL;
	struct pack_idx_entry **idx_objects;
	unsigned char pack_sha1[20];
	int nongit;

	if (argc == 2 && !strcmp(argv[1], "-h"))
		usage(index_pack_usage);

	prefix = setup_git_directory_gently(&nongit);
	git_config(git_index_pack_config, NULL);
	if (prefix && chdir(prefix))
		die("Cannot come back to cwd");

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];