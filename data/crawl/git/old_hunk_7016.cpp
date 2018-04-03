			die("HEAD not found below refs/heads!");
		head += 11;
	}

	if (delete)
		return delete_branches(argc, argv, delete > 1, kinds);