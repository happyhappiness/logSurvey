	}

	packet_flush(out);
	if (new_refs && !args.dry_run) {
		if (pack_objects(out, remote_refs, &extra_have) < 0)
			return -1;
	}
	else
		close(out);

	if (expect_status_report)
		ret = receive_status(in, remote_refs);
	else
		ret = 0;

	print_push_status(dest, remote_refs);

	if (!args.dry_run && remote) {
		for (ref = remote_refs; ref; ref = ref->next)
			update_tracking_ref(remote, ref);
	}

	if (!refs_pushed(remote_refs))
		fprintf(stderr, "Everything up-to-date\n");
	if (ret < 0)
		return ret;
	for (ref = remote_refs; ref; ref = ref->next) {
