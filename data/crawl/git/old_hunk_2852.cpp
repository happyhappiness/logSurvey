	return 0;
}

/**
 * Clean the index without touching entries that are not modified between
 * `head` and `remote`.
 */
static int clean_index(const unsigned char *head, const unsigned char *remote)
{
	struct lock_file *lock_file;
	struct tree *head_tree, *remote_tree, *index_tree;
	unsigned char index[GIT_SHA1_RAWSZ];
	struct pathspec pathspec;

	head_tree = parse_tree_indirect(head);
	if (!head_tree)
