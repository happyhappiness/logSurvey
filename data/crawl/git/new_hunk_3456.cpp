
	if (!enter_repo(dir, strict))
		die("'%s' does not appear to be a git repository", dir);
	if (is_repository_shallow() && stateless_rpc)
		die("attempt to push into a shallow repository");

	git_config(upload_pack_config, NULL);
	upload_pack();
	return 0;