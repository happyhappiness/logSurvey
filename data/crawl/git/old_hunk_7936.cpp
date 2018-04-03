		return -1;

	if (!remote_refs) {
		fprintf(stderr, "No refs in common and none specified; doing nothing.\n");
		return 0;
	}
