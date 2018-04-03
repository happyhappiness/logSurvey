	if (argc == 0)
		die("You must specify a repository to clone.");

	if (option_no_hardlinks)
		use_local_hardlinks = 0;

	if (option_mirror)
		option_bare = 1;

