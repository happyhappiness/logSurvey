		break;
	default:
		current_branch = branch_get(NULL);
		upstream = branch_get_upstream(current_branch);
		if (!upstream) {
			fprintf(stderr, _("Could not find a tracked"
					" remote branch, please"
