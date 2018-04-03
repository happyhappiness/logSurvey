		if (!(flags & TRANSPORT_PUSH_DRY_RUN)) {
			struct ref *ref;
			for (ref = remote_refs; ref; ref = ref->next)
				transport_update_tracking_ref(transport->remote, ref, verbose);
		}

		if (!quiet && !ret && !transport_refs_pushed(remote_refs))
			fprintf(stderr, "Everything up-to-date\n");
		return ret;
	}
