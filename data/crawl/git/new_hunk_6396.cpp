int transport_push(struct transport *transport,
		   int refspec_nr, const char **refspec, int flags)
{
	verify_remote_names(refspec_nr, refspec);

	if (transport->push)
		return transport->push(transport, refspec_nr, refspec, flags);
	if (transport->push_refs) {
		struct ref *remote_refs =
			transport->get_refs_list(transport, 1);
		struct ref **remote_tail;
		struct ref *local_refs = get_local_heads();
		int match_flags = MATCH_REFS_NONE;
		int verbose = flags & TRANSPORT_PUSH_VERBOSE;
		int ret;

		if (flags & TRANSPORT_PUSH_ALL)
			match_flags |= MATCH_REFS_ALL;
		if (flags & TRANSPORT_PUSH_MIRROR)
			match_flags |= MATCH_REFS_MIRROR;

		remote_tail = &remote_refs;
		while (*remote_tail)
			remote_tail = &((*remote_tail)->next);
		if (match_refs(local_refs, remote_refs, &remote_tail,
			       refspec_nr, refspec, match_flags)) {
			return -1;
		}

		ret = transport->push_refs(transport, remote_refs, flags);

		print_push_status(transport->url, remote_refs, verbose);

		if (!(flags & TRANSPORT_PUSH_DRY_RUN)) {
			struct ref *ref;
			for (ref = remote_refs; ref; ref = ref->next)
				update_tracking_ref(transport->remote, ref, verbose);
		}

		if (!ret && !refs_pushed(remote_refs))
			fprintf(stderr, "Everything up-to-date\n");
		return ret;
	}
	return 1;
}

const struct ref *transport_get_remote_refs(struct transport *transport)
{
	if (!transport->remote_refs)
		transport->remote_refs = transport->get_refs_list(transport, 0);
	return transport->remote_refs;
}

