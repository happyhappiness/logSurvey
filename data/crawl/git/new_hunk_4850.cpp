			    o->diff_rename_limit >= 0 ? o->diff_rename_limit :
			    500;
	opts.rename_score = o->rename_score;
	opts.output_format = DIFF_FORMAT_NO_OUTPUT;
	if (diff_setup_done(&opts) < 0)
		die("diff setup failed");
	diff_tree_sha1(o_tree->object.sha1, tree->object.sha1, "", &opts);
	diffcore_std(&opts);
	if (opts.needed_rename_limit > o->needed_rename_limit)
		o->needed_rename_limit = opts.needed_rename_limit;
	for (i = 0; i < diff_queued_diff.nr; ++i) {
		struct string_list_item *item;
		struct rename *re;
