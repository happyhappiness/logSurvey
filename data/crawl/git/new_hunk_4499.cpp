		return 0;

	if (nonfastforward && advice_push_nonfastforward) {
		fprintf(stderr, _("To prevent you from losing history, non-fast-forward updates were rejected\n"
				"Merge the remote changes (e.g. 'git pull') before pushing again.  See the\n"
				"'Note about fast-forwards' section of 'git push --help' for details.\n"));
	}

	return 1;
