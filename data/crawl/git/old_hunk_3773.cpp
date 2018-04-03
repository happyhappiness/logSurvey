	real_ref = NULL;
	if (get_sha1(start_name, sha1)) {
		if (explicit_tracking)
			die(_(upstream_missing));
		die("Not a valid object name: '%s'.", start_name);
	}

	switch (dwim_ref(start_name, strlen(start_name), sha1, &real_ref)) {
	case 0:
		/* Not branching from any existing branch */
		if (explicit_tracking)
			die(_(upstream_not_branch));
		break;
	case 1:
		/* Unique completion -- good, only if it is a real branch */
		if (prefixcmp(real_ref, "refs/heads/") &&
		    prefixcmp(real_ref, "refs/remotes/")) {
			if (explicit_tracking)
				die(_(upstream_not_branch));
			else
				real_ref = NULL;
		}