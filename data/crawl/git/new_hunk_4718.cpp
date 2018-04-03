		rename_branch(argv[0], argv[1], rename > 1);
	else if (argc <= 2) {
		if (kinds != REF_LOCAL_BRANCH)
			die(_("-a and -r options to 'git branch' do not make sense with a branch name"));
		create_branch(head, argv[0], (argc == 2) ? argv[1] : head,
			      force_create, reflog, track);
	} else