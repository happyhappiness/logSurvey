	}

	if (opts.force && opts.merge)
		die("git checkout: -f and -m are incompatible");

	/*
	 * case 1: git checkout <ref> -- [<paths>]
