		if (is_null_sha1(ref->peer_ref->new_sha1)) {
			if (delete_remote_branch(ref->name, 1) == -1) {
				error("Could not remove %s", ref->name);
				rc = -4;
			}
			new_refs++;
			continue;
		}

		if (!hashcmp(ref->old_sha1, ref->peer_ref->new_sha1)) {
			if (push_verbosely || 1)
				fprintf(stderr, "'%s': up-to-date\n", ref->name);
			continue;
		}

