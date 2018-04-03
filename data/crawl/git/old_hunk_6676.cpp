	char *index_name_buf = NULL, *keep_name_buf = NULL;
	struct pack_idx_entry **idx_objects;
	unsigned char pack_sha1[20];
	int nongit = 0;

	setup_git_directory_gently(&nongit);
	git_config(git_index_pack_config, NULL);

	for (i = 1; i < argc; i++) {
		char *arg = argv[i];
