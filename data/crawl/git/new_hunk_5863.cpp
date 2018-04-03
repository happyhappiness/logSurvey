
		setup_work_tree();
		if (!has_string_in_work_tree(path))
			die_errno("cannot stat path '%s'", path);
	}

	setup_revisions(argc, argv, &revs, NULL);
