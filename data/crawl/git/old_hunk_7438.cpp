	switch (dwim_ref(start_name, strlen(start_name), sha1, &real_ref)) {
	case 0:
		/* Not branching from any existing branch */
		real_ref = NULL;
		break;
	case 1:
		/* Unique completion -- good */
