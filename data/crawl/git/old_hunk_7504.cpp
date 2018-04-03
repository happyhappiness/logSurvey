		die("failed to unpack HEAD tree object");
	parse_tree(tree);
	init_tree_desc(&t, tree->buffer, tree->size);
	unpack_trees(1, &t, &opts);
}

static char *prepare_index(int argc, const char **argv, const char *prefix)
