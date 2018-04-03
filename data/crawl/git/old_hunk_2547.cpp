		return -1;
	printf("%s %s\n", sha1_to_hex(tree1->object.sha1),
			  sha1_to_hex(tree2->object.sha1));
	diff_tree_sha1(tree1->object.sha1, tree2->object.sha1,
		       "", &log_tree_opt.diffopt);
	log_tree_diff_flush(&log_tree_opt);
	return 0;
