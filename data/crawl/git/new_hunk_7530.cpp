	if (argc > 2)
		die("too many options");

	ret = write_cache_as_tree(sha1, missing_ok, prefix);
	switch (ret) {
	case 0:
		printf("%s\n", sha1_to_hex(sha1));
		break;
	case WRITE_TREE_UNREADABLE_INDEX:
		die("%s: error reading the index", me);
		break;
	case WRITE_TREE_UNMERGED_INDEX:
		die("%s: error building trees; the index is unmerged?", me);
		break;
	case WRITE_TREE_PREFIX_ERROR:
		die("%s: prefix %s not found", me, prefix);
		break;
	}
	return ret;
}
