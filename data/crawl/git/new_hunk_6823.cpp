	return clean_merge;
}

int merge_trees(struct merge_options *o,
		struct tree *head,
		struct tree *merge,
		struct tree *common,
		struct tree **result)
{
	int code, clean;

	if (o->subtree_merge) {
		merge = shift_tree_object(head, merge);
		common = shift_tree_object(head, common);
	}

	if (sha_eq(common->object.sha1, merge->object.sha1)) {
		output(o, 0, "Already uptodate!");
		*result = head;
		return 1;
	}
