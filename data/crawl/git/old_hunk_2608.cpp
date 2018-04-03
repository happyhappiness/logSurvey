		if (!ref->peer_ref)
			continue;

		if (is_null_sha1(ref->peer_ref->new_sha1)) {
			if (delete_remote_branch(ref->name, 1) == -1) {
				error("Could not remove %s", ref->name);
				if (helper_status)
