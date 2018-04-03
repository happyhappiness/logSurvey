	unsigned long size1, size2;
	int retval;

	tree1 = fill_tree_descriptor(&t1, old);
	tree2 = fill_tree_descriptor(&t2, new);
	size1 = t1.size;
	size2 = t2.size;
	retval = diff_tree(&t1, &t2, base, opt);
	if (!*base && DIFF_OPT_TST(opt, FOLLOW_RENAMES) && diff_might_be_rename()) {
		init_tree_desc(&t1, tree1, size1);