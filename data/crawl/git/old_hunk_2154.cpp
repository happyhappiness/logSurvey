{
	unsigned char result_tree[20], result_commit[20];
	struct commit_list *parents, **pptr = &parents;

	write_tree_trivial(result_tree);
	printf(_("Wonderful.\n"));
