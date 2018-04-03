	} else if (!strcmp(arg, "--left-right")) {
		revs->left_right = 1;
	} else if (!strcmp(arg, "--left-only")) {
		revs->left_only = 1;
	} else if (!strcmp(arg, "--right-only")) {
		revs->right_only = 1;
	} else if (!strcmp(arg, "--count")) {
		revs->count = 1;