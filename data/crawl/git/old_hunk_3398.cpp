	return ret;
}

static int prune_refs(struct refspec *refs, int ref_count, struct ref *ref_map)
{
	int result = 0;
	struct ref *ref, *stale_refs = get_stale_heads(refs, ref_count, ref_map);
	const char *dangling_msg = dry_run
		? _("   (%s will become dangling)")
		: _("   (%s has become dangling)");

	for (ref = stale_refs; ref; ref = ref->next) {
		if (!dry_run)
			result |= delete_ref(ref->name, NULL, 0);
		if (verbosity >= 0) {
			fprintf(stderr, " x %-*s %-*s -> %s\n",
				TRANSPORT_SUMMARY(_("[deleted]")),
				REFCOL_WIDTH, _("(none)"), prettify_refname(ref->name));
			warn_dangling_symref(stderr, dangling_msg, ref->name);
		}
	}
	free_refs(stale_refs);
	return result;
}
