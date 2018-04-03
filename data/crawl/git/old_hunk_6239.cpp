	sigchain_push_common(remove_locks_on_signal);

	/* Check whether the remote has server info files */
	remote->can_update_info_refs = 0;
	remote->has_info_refs = remote_exists("info/refs");
	remote->has_info_packs = remote_exists("objects/info/packs");
	if (remote->has_info_refs) {
		info_ref_lock = lock_remote("info/refs", LOCK_TIME);
		if (info_ref_lock)
			remote->can_update_info_refs = 1;
		else {
			fprintf(stderr, "Error: cannot lock existing info/refs\n");
			rc = 1;
			goto cleanup;
		}
	}
	if (remote->has_info_packs)
		fetch_indices();

	/* Get a list of all local and remote heads to validate refspecs */
	get_local_heads();
	fprintf(stderr, "Fetching remote heads...\n");
	get_dav_remote_heads();

