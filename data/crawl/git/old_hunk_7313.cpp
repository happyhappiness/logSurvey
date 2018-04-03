#include "dir.h"
#include "builtin.h"

#define MAX_TREES 8
static int nr_trees;
static struct tree *trees[MAX_TREES];

static int list_tree(unsigned char *sha1)
{
	struct tree *tree;

	if (nr_trees >= MAX_TREES)
		die("I cannot read more than %d trees", MAX_TREES);
	tree = parse_tree_indirect(sha1);
	if (!tree)
		return -1;
