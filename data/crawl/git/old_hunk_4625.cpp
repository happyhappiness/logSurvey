	int result = 0;
	struct ref *ref, *stale_refs = get_stale_heads(transport->remote, ref_map);
	const char *dangling_msg = dry_run
		? "   (%s will become dangling)\n"
		: "   (%s has become dangling)\n";

	for (ref = stale_refs; ref; ref = ref->next) {
		if (!dry_run)
			result |= delete_ref(ref->name, NULL, 0);
		if (verbosity >= 0) {
			fprintf(stderr, " x %-*s %-*s -> %s\n",
				TRANSPORT_SUMMARY_WIDTH, "[deleted]",
				REFCOL_WIDTH, "(none)", prettify_refname(ref->name));
			warn_dangling_symref(stderr, dangling_msg, ref->name);
		}
	}
