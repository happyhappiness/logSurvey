	bases = get_merge_bases(local, remote, 1);
	if (!bases) {
		base_sha1 = null_sha1;
		base_tree_sha1 = (unsigned char *)EMPTY_TREE_SHA1_BIN;
		OUTPUT(o, 4, "No merge base found; doing history-less merge");
	} else if (!bases->next) {
		base_sha1 = bases->item->object.sha1;
		base_tree_sha1 = bases->item->tree->object.sha1;
		OUTPUT(o, 4, "One merge base found (%.7s)",
		       sha1_to_hex(base_sha1));
	} else {
		/* TODO: How to handle multiple merge-bases? */
		base_sha1 = bases->item->object.sha1;
		base_tree_sha1 = bases->item->tree->object.sha1;
		OUTPUT(o, 3, "Multiple merge bases found. Using the first "
		       "(%.7s)", sha1_to_hex(base_sha1));
	}
