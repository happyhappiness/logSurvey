	parent->next->item = remoteheads->item;
	parent->next->next = NULL;
	prepare_to_commit();
	commit_tree(merge_msg.buf, result_tree, parent, result_commit, NULL);
	finish(head, result_commit, "In-index merge");
	drop_save();
	return 0;
