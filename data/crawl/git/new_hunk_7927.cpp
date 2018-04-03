			ret = -4;
	}

	if (!dry_run && remote && ret == 0) {
		for (ref = remote_refs; ref; ref = ref->next)
			update_tracking_ref(remote, ref);
	}

	if (!new_refs && ret == 0)
		fprintf(stderr, "Everything up-to-date\n");
	return ret;