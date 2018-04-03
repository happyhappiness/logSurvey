	free(to_free);
}

static int calc_maxwidth(struct ref_list *refs, int remote_bonus)
{
	int i, max = 0;
	for (i = 0; i < refs->index; i++) {
		struct ref_item *it = &refs->list[i];
		int w;

		if (it->ignore)
			continue;
		w = utf8_strwidth(it->name);
		if (it->kind == REF_REMOTE_BRANCH)
			w += remote_bonus;
		if (w > max)
			max = w;
	}
	return max;
}

static void print_ref_list(int kinds, int detached, int verbose, int abbrev, struct commit_list *with_commit, const char **pattern)
{
	int i;
	struct append_ref_cb cb;
	struct ref_list ref_list;
	int maxwidth = 0;
	const char *remote_prefix = "";

	/*
	 * If we are listing more than just remote branches,
	 * then remote branches will have a "remotes/" prefix.
	 * We need to account for this in the width.
	 */
	if (kinds != REF_REMOTE_BRANCH)
		remote_prefix = "remotes/";

	memset(&ref_list, 0, sizeof(ref_list));
	ref_list.kinds = kinds;
	ref_list.verbose = verbose;
	ref_list.abbrev = abbrev;
	ref_list.with_commit = with_commit;
	if (merge_filter != NO_FILTER)
		init_revisions(&ref_list.revs, NULL);
	cb.ref_list = &ref_list;
	cb.pattern = pattern;
	/*
	 * First we obtain all regular branch refs and if the HEAD is
	 * detached then we insert that ref to the end of the ref_fist
	 * so that it can be printed and removed first.
	 */
	for_each_rawref(append_ref, &cb);
	if (detached)
		head_ref(append_ref, &cb);
	/*
	 * The following implementation is currently duplicated in ref-filter. It
	 * will eventually be removed when we port branch.c to use ref-filter APIs.
	 */
	if (merge_filter != NO_FILTER) {
		struct commit *filter;
		filter = lookup_commit_reference_gently(merge_filter_ref, 0);
		if (!filter)
			die(_("object '%s' does not point to a commit"),
			    sha1_to_hex(merge_filter_ref));

		filter->object.flags |= UNINTERESTING;
		add_pending_object(&ref_list.revs,
				   (struct object *) filter, "");
		ref_list.revs.limited = 1;

		if (prepare_revision_walk(&ref_list.revs))
			die(_("revision walk setup failed"));

		for (i = 0; i < ref_list.index; i++) {
			struct ref_item *item = &ref_list.list[i];
			struct commit *commit = item->commit;
			int is_merged = !!(commit->object.flags & UNINTERESTING);
			item->ignore = is_merged != (merge_filter == SHOW_MERGED);
		}

		for (i = 0; i < ref_list.index; i++) {
			struct ref_item *item = &ref_list.list[i];
			clear_commit_marks(item->commit, ALL_REV_FLAGS);
		}
		clear_commit_marks(filter, ALL_REV_FLAGS);
	}
	if (verbose)
		maxwidth = calc_maxwidth(&ref_list, strlen(remote_prefix));

	qsort(ref_list.list, ref_list.index, sizeof(struct ref_item), ref_cmp);

	for (i = 0; i < ref_list.index; i++)
		print_ref_item(&ref_list.list[i], maxwidth, verbose,
			       abbrev, detached, remote_prefix);

	free_ref_list(&ref_list);
}

static void rename_branch(const char *oldname, const char *newname, int force)
