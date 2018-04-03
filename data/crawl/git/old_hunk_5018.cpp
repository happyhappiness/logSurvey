			die("failed to unpack tree object %s", arg);
		stage++;
	}
	if (1 < opts.index_only + opts.update)
		die("-u and -i at the same time makes no sense");
	if ((opts.update||opts.index_only) && !opts.merge)