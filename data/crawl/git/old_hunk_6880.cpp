		if (argc != 1)
			die("Can merge only exactly one commit into "
				"empty head");
		remote_head = peel_to_type(argv[0], 0, NULL, OBJ_COMMIT);
		if (!remote_head)
			die("%s - not something we can merge", argv[0]);