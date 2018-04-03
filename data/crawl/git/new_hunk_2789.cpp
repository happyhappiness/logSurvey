			die(_("branch name required"));
		return delete_branches(argc, argv, delete > 1, kinds, quiet);
	} else if (list) {
		/*  git branch --local also shows HEAD when it is detached */
		if (kinds & REF_LOCAL_BRANCH)
			kinds |= REF_DETACHED_HEAD;
		print_ref_list(kinds, detached, verbose, abbrev,
					 with_commit, argv);
		print_columns(&output, colopts, NULL);
		string_list_clear(&output, 0);
		return 0;
	}
	else if (edit_description) {
		const char *branch_name;