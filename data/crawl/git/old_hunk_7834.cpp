	for (ref = remote_refs; ref; ref = ref->next) {
		char old_hex[60], *new_hex;
		int will_delete_ref;

		if (!ref->peer_ref)
			continue;


		will_delete_ref = is_null_sha1(ref->peer_ref->new_sha1);
		if (will_delete_ref && !allow_deleting_refs) {
			error("remote does not support deleting refs");
			ret = -2;
			continue;
		}
		if (!will_delete_ref &&
		    !hashcmp(ref->old_sha1, ref->peer_ref->new_sha1)) {
			if (args.verbose)
				fprintf(stderr, "'%s': up-to-date\n", ref->name);
			continue;
		}

