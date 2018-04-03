		struct transport *transport;
		const struct ref *ref;
		struct strbuf buf;
		int i;

		states.remote = remote_get(*argv);
		if (!states.remote)
			return error("No such remote: %s", *argv);

		read_branches();

		if (!no_query) {
			transport = transport_get(NULL,
				states.remote->url_nr > 0 ?
				states.remote->url[0] : NULL);
			ref = transport_get_remote_refs(transport);
			transport_disconnect(transport);

			get_ref_states(ref, &states);
		}

		if (prune) {
			for (i = 0; i < states.stale.nr; i++) {
