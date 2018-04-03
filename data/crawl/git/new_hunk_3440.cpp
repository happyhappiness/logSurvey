	if (!enter_repo(dir, 0))
		die("'%s' does not appear to be a git repository", dir);

	git_config(receive_pack_config, NULL);

	if (0 <= transfer_unpack_limit)
