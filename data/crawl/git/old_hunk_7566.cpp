		info_ref_lock = lock_remote("info/refs", LOCK_TIME);
		if (info_ref_lock)
			remote->can_update_info_refs = 1;
	}
	if (remote->has_info_packs)
		fetch_indices();