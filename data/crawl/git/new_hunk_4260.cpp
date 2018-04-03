		destination = copy_pathspec(dest_path[0], argv, argc, 1);
	} else {
		if (argc != 1)
			die("destination '%s' is not a directory", dest_path[0]);
		destination = dest_path;
	}
