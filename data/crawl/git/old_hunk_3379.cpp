	}
}

static void load_tree_desc(struct tree_desc *desc, void **tree,
			   const unsigned char *sha1)
{
	unsigned long size;
	*tree = read_object_with_reference(sha1, tree_type, &size, NULL);
	if (!*tree)
		die("Unable to read tree (%s)", sha1_to_hex(sha1));
	init_tree_desc(desc, *tree, size);
}

static int count_parents(struct commit *commit)
{
	struct commit_list *parents = commit->parents;
