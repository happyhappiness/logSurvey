	case 0:
		/* Not branching from any existing branch */
		if (explicit_tracking)
			die("Cannot setup tracking information; starting point is not a branch.");
		break;
	case 1:
		/* Unique completion -- good, only if it is a real branch */
		if (prefixcmp(real_ref, "refs/heads/") &&
		    prefixcmp(real_ref, "refs/remotes/")) {
			if (explicit_tracking)
				die("Cannot setup tracking information; starting point is not a branch.");
			else
				real_ref = NULL;
		}