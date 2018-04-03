	char *index_name_buf = NULL, *keep_name_buf = NULL;
	struct pack_idx_entry **idx_objects;
	unsigned char pack_sha1[20];

	/*
	 * We wish to read the repository's config file if any, and
	 * for that it is necessary to call setup_git_directory_gently().
	 * However if the cwd was inside .git/objects/pack/ then we need
	 * to go back there or all the pack name arguments will be wrong.
	 * And in that case we cannot rely on any prefix returned by
	 * setup_git_directory_gently() either.
	 */
	{
		char cwd[PATH_MAX+1];
		int nongit;

		if (!getcwd(cwd, sizeof(cwd)-1))
			die("Unable to get current working directory");
		setup_git_directory_gently(&nongit);
		git_config(git_index_pack_config, NULL);
		if (chdir(cwd))
			die("Cannot come back to cwd");
	}

	for (i = 1; i < argc; i++) {
		char *arg = argv[i];
