			die_errno("cannot stat path '%s'", path);
	}

	setup_revisions(argc, argv, &revs, NULL);
	memset(&sb, 0, sizeof(sb));

