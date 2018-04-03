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