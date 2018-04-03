			die("failed to unpack tree object %s", arg);
		stage++;
	}
	if (nr_trees == 0 && !read_empty)
		warning("read-tree: emptying the index with no arguments is deprecated; use --empty");
	else if (nr_trees > 0 && read_empty)
		die("passing trees as arguments contradicts --empty");

	if (1 < opts.index_only + opts.update)
		die("-u and -i at the same time makes no sense");
	if ((opts.update||opts.index_only) && !opts.merge)