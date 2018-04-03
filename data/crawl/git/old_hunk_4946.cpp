	diff_tree_release_paths(&opt);
}

static int merge_one_change(struct notes_merge_options *o,
			    struct notes_merge_pair *p, struct notes_tree *t)
{
	/*
	 * Return 0 if change was resolved (and added to notes_tree),
	 * 1 if conflict
	 */
	switch (o->strategy) {
	case NOTES_MERGE_RESOLVE_MANUAL:
		return 1;
	case NOTES_MERGE_RESOLVE_OURS:
		OUTPUT(o, 2, "Using local notes for %s", sha1_to_hex(p->obj));
		/* nothing to do */
