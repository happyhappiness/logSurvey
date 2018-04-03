		fetch_indices();

	/* Get a list of all local and remote heads to validate refspecs */
	get_local_heads();
	fprintf(stderr, "Fetching remote heads...\n");
	get_dav_remote_heads();

