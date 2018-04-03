
		if (check_ref_format(argv[2]))
			exit(1);
		collapse_slashes(refname, argv[2]);
		printf("%s\n", refname);
		exit(0);
	}