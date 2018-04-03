	if (argc == 0)
		die("You must specify a repository to clone.");

	if (option_mirror)
		option_bare = 1;

