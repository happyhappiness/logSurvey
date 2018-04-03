	if (!remote) {
		if (repo)
			die("bad repository '%s'", repo);
		die("No destination configured to push to.");
	}

	if (remote->mirror)