	diff_setup(&opt);
	DIFF_OPT_SET(&opt, RECURSIVE);
	opt.output_format = DIFF_FORMAT_NO_OUTPUT;
	if (diff_setup_done(&opt) < 0)
		die("diff_setup_done failed");
	diff_tree_sha1(base, remote, "", &opt);
	diffcore_std(&opt);

