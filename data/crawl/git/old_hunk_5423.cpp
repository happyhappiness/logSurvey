	ret |= finish_connect(conn);

	if (!helper_status)
		print_push_status(dest, remote_refs);

	if (!args.dry_run && remote) {
		struct ref *ref;
		for (ref = remote_refs; ref; ref = ref->next)
			update_tracking_ref(remote, ref);
	}

	if (!ret && !refs_pushed(remote_refs))
		fprintf(stderr, "Everything up-to-date\n");

	return ret;
