	init_hash(&names);
	for_each_rawref(get_name, NULL);
	if (!names.nr && !always)
		die(_("No names found, cannot describe anything."));

	if (argc == 0) {
		if (dirty && !cmd_diff_index(ARRAY_SIZE(diff_index_args) - 1, diff_index_args, prefix))
			dirty = NULL;
		describe("HEAD", 1);
	} else if (dirty) {
		die(_("--dirty is incompatible with committishes"));
	} else {
		while (argc-- > 0) {
			describe(*argv++, argc == 0);
