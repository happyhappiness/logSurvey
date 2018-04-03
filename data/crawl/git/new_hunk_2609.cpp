			continue;
		}

		if (!oidcmp(&ref->old_oid, &ref->peer_ref->new_oid)) {
			if (push_verbosely)
				fprintf(stderr, "'%s': up-to-date\n", ref->name);
			if (helper_status)
