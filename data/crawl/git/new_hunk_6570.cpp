			or die_error(500, "Open git-diff-tree failed");
	}

	# old/legacy style URI -- not generated anymore since 1.4.3.
	if (!%diffinfo) {
		die_error('404 Not Found', "Missing one of the blob diff parameters")
	}

	# header