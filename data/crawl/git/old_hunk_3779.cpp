		if (edit_branch_description(branch_name))
			return 1;
	} else if (rename) {
		if (argc == 1)
			rename_branch(head, argv[0], rename > 1);
		else if (argc == 2)
			rename_branch(argv[0], argv[1], rename > 1);
