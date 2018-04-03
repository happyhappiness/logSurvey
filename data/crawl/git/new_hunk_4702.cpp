	}

	if (opts.force && opts.merge)
		die(_("git checkout: -f and -m are incompatible"));

	/*
	 * case 1: git checkout <ref> -- [<paths>]
