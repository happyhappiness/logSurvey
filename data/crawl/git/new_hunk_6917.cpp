	}
	if (argc != 3)
		usage(merge_base_usage);
	rev1 = get_commit_reference(argv[1]);
	rev2 = get_commit_reference(argv[2]);

	return show_merge_base(rev1, rev2, show_all);
}