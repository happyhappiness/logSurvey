	}

	packet_flush(out);
	if (new_refs && !args->dry_run) {
		if (pack_objects(out, remote_refs, extra_have, args) < 0) {
			for (ref = remote_refs; ref; ref = ref->next)
				ref->status = REF_STATUS_NONE;
			return -1;
		}
	}

	if (expect_status_report)
		ret = receive_status(in, remote_refs);
	else
		ret = 0;

	if (ret < 0)
		return ret;
	for (ref = remote_refs; ref; ref = ref->next) {
