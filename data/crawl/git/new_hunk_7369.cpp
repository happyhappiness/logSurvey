
static int read_tree_some(struct tree *tree, const char **pathspec)
{
	read_tree_recursive(tree, "", 0, 0, pathspec, update_some);

	/* update the index with the given tree's info
	 * for all args, expanding wildcards, and exit
	 * with any non-zero return code.
	 */
	return 0;
}

static int checkout_paths(struct tree *source_tree, const char **pathspec)
{
	int pos;
	struct checkout state;
