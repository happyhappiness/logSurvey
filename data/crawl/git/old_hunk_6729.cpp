		return checkout_paths(source_tree, pathspec);
	}

	if (new.name && !new.commit) {
		die("Cannot switch branch to a non-commit.");
	}
