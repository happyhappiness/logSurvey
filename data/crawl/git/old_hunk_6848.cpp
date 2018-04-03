	if (new.name && !new.commit) {
		die("Cannot switch branch to a non-commit.");
	}

	return switch_branches(&opts, &new);
}
