static int merge_trivial(void)
{
	unsigned char result_tree[20], result_commit[20];
	struct commit_list parent;

	write_tree_trivial(result_tree);
	printf("Wonderful.\n");
	parent.item = remoteheads->item;
	parent.next = NULL;
	commit_tree(merge_msg.buf, result_tree, &parent, result_commit);
	finish(result_commit, "In-index merge");
	drop_save();
	return 0;
