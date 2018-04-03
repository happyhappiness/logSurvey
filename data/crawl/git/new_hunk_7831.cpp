		return;

	if (!remote_find_tracking(remote, &rs)) {
		if (args.verbose)
			fprintf(stderr, "updating local tracking ref '%s'\n", rs.dst);
		if (is_null_sha1(ref->peer_ref->new_sha1)) {
			if (delete_ref(rs.dst, NULL))
				error("Failed to delete");