	}
	if (unpack_trees(nr_trees, t, &opts))
		return -1;
	if (write_locked_index(&the_index, lock_file, COMMIT_LOCK))
		die(_("unable to write new index file"));
	return 0;
}