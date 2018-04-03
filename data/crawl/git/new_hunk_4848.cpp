	} else if (!strcmp(arg, "--left-right")) {
		revs->left_right = 1;
	} else if (!strcmp(arg, "--left-only")) {
		if (revs->right_only)
			die("--left-only is incompatible with --right-only");
		revs->left_only = 1;
	} else if (!strcmp(arg, "--right-only")) {
		if (revs->left_only)
			die("--right-only is incompatible with --left-only");
		revs->right_only = 1;
	} else if (!strcmp(arg, "--count")) {
		revs->count = 1;