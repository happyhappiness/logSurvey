				      with_commit, argv);
	else if (edit_description) {
		const char *branch_name;
		if (detached)
			die("Cannot give description to detached HEAD");
		if (!argc)
