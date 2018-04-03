	}

	if (res) {
		error("could not %s %s... %s",
		      action == REVERT ? "revert" : "apply",
		      find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV),
		      msg.subject);
		print_advice();
