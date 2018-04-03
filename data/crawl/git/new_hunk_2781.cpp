	free(to_free);
}

static int calc_maxwidth(struct ref_array *refs, int remote_bonus)
{
	int i, max = 0;
	for (i = 0; i < refs->nr; i++) {
		struct ref_array_item *it = refs->items[i];
		int w;

		if (it->ignore)
			continue;
		w = utf8_strwidth(it->refname);
		if (it->kind == FILTER_REFS_REMOTES)
			w += remote_bonus;
		if (w > max)
			max = w;
	}
	return max;
}

static void print_ref_list(struct ref_filter *filter)
{
	int i;
	struct ref_array array;
	struct ref_filter_cbdata data;
	int maxwidth = 0;
	const char *remote_prefix = "";
	struct rev_info revs;

	/*
	 * If we are listing more than just remote branches,
	 * then remote branches will have a "remotes/" prefix.
	 * We need to account for this in the width.
	 */
	if (filter->kind != FILTER_REFS_REMOTES)
		remote_prefix = "remotes/";

	memset(&array, 0, sizeof(array));
	if (filter->merge != REF_FILTER_MERGED_NONE)
		init_revisions(&revs, NULL);

	data.array = &array;
	data.filter = filter;
	array.revs = &revs;

	/*
	 * First we obtain all regular branch refs and if the HEAD is
	 * detached then we insert that ref to the end of the ref_fist
	 * so that it can be printed and removed first.
	 */
	for_each_rawref(append_ref, &data);
	if (filter->detached)
		head_ref(append_ref, &data);
	/*
	 * The following implementation is currently duplicated in ref-filter. It
	 * will eventually be removed when we port branch.c to use ref-filter APIs.
	 */
	if (filter->merge != REF_FILTER_MERGED_NONE) {
		filter->merge_commit->object.flags |= UNINTERESTING;
		add_pending_object(&revs, &filter->merge_commit->object, "");
		revs.limited = 1;

		if (prepare_revision_walk(&revs))
			die(_("revision walk setup failed"));

		for (i = 0; i < array.nr; i++) {
			struct ref_array_item *item = array.items[i];
			struct commit *commit = item->commit;
			int is_merged = !!(commit->object.flags & UNINTERESTING);
			item->ignore = is_merged != (filter->merge == REF_FILTER_MERGED_INCLUDE);
		}

		for (i = 0; i < array.nr; i++) {
			struct ref_array_item *item = array.items[i];
			clear_commit_marks(item->commit, ALL_REV_FLAGS);
		}
		clear_commit_marks(filter->merge_commit, ALL_REV_FLAGS);
	}

	if (filter->verbose)
		maxwidth = calc_maxwidth(&array, strlen(remote_prefix));

	qsort(array.items, array.nr, sizeof(struct ref_array_item *), ref_cmp);

	for (i = 0; i < array.nr; i++)
		print_ref_item(array.items[i], maxwidth, filter, remote_prefix);

	ref_array_clear(&array);
}

static void rename_branch(const char *oldname, const char *newname, int force)
