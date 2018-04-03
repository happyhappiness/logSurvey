	tree2 = lookup_tree(sha1);
	if (!tree2 || parse_tree(tree2))
		return -1;
	printf("%s %s\n", oid_to_hex(&tree1->object.oid),
			  oid_to_hex(&tree2->object.oid));
	diff_tree_sha1(get_object_hash(tree1->object), get_object_hash(tree2->object),
		       "", &log_tree_opt.diffopt);
	log_tree_diff_flush(&log_tree_opt);
