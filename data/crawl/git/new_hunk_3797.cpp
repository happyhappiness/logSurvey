	}
}

static int iterate_ref_map(void *cb_data, unsigned char sha1[20])
{
	struct ref **rm = cb_data;
	struct ref *ref = *rm;

	/*
	 * Skip anything missing a peer_ref, which we are not
	 * actually going to write a ref for.
	 */
	while (ref && !ref->peer_ref)
		ref = ref->next;
	/* Returning -1 notes "end of list" to the caller. */
	if (!ref)
		return -1;

	hashcpy(sha1, ref->old_sha1);
	*rm = ref->next;
	return 0;
}

static void update_remote_refs(const struct ref *refs,
			       const struct ref *mapped_refs,
			       const struct ref *remote_head_points_at,
			       const char *branch_top,
			       const char *msg)
{
	const struct ref *rm = mapped_refs;

	if (check_everything_connected(iterate_ref_map, 0, &rm))
		die(_("remote did not send all necessary objects"));

	if (refs) {
		write_remote_refs(mapped_refs);
		if (option_single_branch)
