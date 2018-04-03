	unsigned char type;
	struct leaf_node *l;

	buf = fill_tree_descriptor(&desc, &subtree->val_oid);
	if (!buf)
		die("Could not read %s for notes-index",
		     oid_to_hex(&subtree->val_oid));
