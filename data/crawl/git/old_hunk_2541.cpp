		unsigned int mode;
		int err;

		err = get_tree_entry(tree->object.sha1, prefix,
				     tree_oid.hash, &mode);
		if (err || !S_ISDIR(mode))
			die("current working directory is untracked");
