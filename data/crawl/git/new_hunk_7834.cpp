	for (ref = remote_refs; ref; ref = ref->next) {
		char old_hex[60], *new_hex;
		int will_delete_ref;
		const char *pretty_ref;
		const char *pretty_peer;

		if (!ref->peer_ref)
			continue;

		if (!shown_dest) {
			fprintf(stderr, "To %s\n", dest);
			shown_dest = 1;
		}

		pretty_ref = prettify_ref(ref->name);
		pretty_peer = prettify_ref(ref->peer_ref->name);

		will_delete_ref = is_null_sha1(ref->peer_ref->new_sha1);
		if (will_delete_ref && !allow_deleting_refs) {
			fprintf(stderr, " ! %-*s %s (remote does not support deleting refs)\n",
					SUMMARY_WIDTH, "[rejected]", pretty_ref);
			ret = -2;
			continue;
		}
		if (!will_delete_ref &&
		    !hashcmp(ref->old_sha1, ref->peer_ref->new_sha1)) {
			if (args.verbose)
				fprintf(stderr, " = %-*s %s -> %s\n",
					SUMMARY_WIDTH, "[up to date]",
					pretty_peer, pretty_ref);
			continue;
		}

