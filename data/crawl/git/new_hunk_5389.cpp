		return 0;

	if (nonfastforward && advice_push_nonfastforward) {
		fprintf(stderr, "To prevent you from losing history, non-fast-forward updates were rejected\n"
				"Merge the remote changes before pushing again.  See the 'Note about\n"
				"fast-forwards' section of 'git push --help' for details.\n");
	}

	return 1;