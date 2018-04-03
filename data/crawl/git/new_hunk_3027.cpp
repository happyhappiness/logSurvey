		rollback_lock_file(&index_lock);
}

/*
 * The path indicated by rr_item may still have conflict for which we
 * have a recorded resolution, in which case replay it and optionally
 * update it.  Or it may have been resolved by the user and we may
 * only have the preimage for that conflict, in which case the result
 * needs to be recorded as a resolution in a postimage file.
 */
static void do_rerere_one_path(struct string_list_item *rr_item,
			       struct string_list *update)
{
	const char *path = rr_item->string;
	const char *name = (const char *)rr_item->util;

	/* Is there a recorded resolution we could attempt to apply? */
	if (has_rerere_resolution(name)) {
		if (merge(name, path))
			return; /* failed to replay */

		if (rerere_autoupdate)
			string_list_insert(update, path);
		else
			fprintf(stderr,
				"Resolved '%s' using previous resolution.\n",
				path);
		goto mark_resolved;
	}

	/* Let's see if the user has resolved it. */
	if (handle_file(path, NULL, NULL))
		return; /* not yet resolved */

	copy_file(rerere_path(name, "postimage"), path, 0666);
	fprintf(stderr, "Recorded resolution for '%s'.\n", path);
mark_resolved:
	free(rr_item->util);
	rr_item->util = NULL;
}

static int do_plain_rerere(struct string_list *rr, int fd)
{
	struct string_list conflict = STRING_LIST_INIT_DUP;
