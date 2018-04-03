	switch (dwim_ref(start_name, strlen(start_name), sha1, &real_ref)) {
	case 0:
		/* Not branching from any existing branch */
		if (track == BRANCH_TRACK_EXPLICIT)
			die("Cannot setup tracking information; starting point is not a branch.");
		break;
	case 1:
		/* Unique completion -- good */
