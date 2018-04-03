
	if (!enter_repo(dir, strict))
		die("'%s' does not appear to be a git repository", dir);
	if (is_repository_shallow())
		die("attempt to fetch/clone from a shallow repository");
	git_config(upload_pack_config, NULL);
	upload_pack();
	return 0;