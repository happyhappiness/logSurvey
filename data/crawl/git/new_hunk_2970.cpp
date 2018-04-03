	am_run(state, 0);
}

/**
 * Returns true if it is safe to reset HEAD to the ORIG_HEAD, false otherwise.
 *
 * It is not safe to reset HEAD when:
 * 1. git-am previously failed because the index was dirty.
 * 2. HEAD has moved since git-am previously failed.
 */
static int safe_to_abort(const struct am_state *state)
{
	struct strbuf sb = STRBUF_INIT;
	unsigned char abort_safety[GIT_SHA1_RAWSZ], head[GIT_SHA1_RAWSZ];

	if (file_exists(am_path(state, "dirtyindex")))
		return 0;

	if (read_state_file(&sb, state, "abort-safety", 1) > 0) {
		if (get_sha1_hex(sb.buf, abort_safety))
			die(_("could not parse %s"), am_path(state, "abort_safety"));
	} else
		hashclr(abort_safety);

	if (get_sha1("HEAD", head))
		hashclr(head);

	if (!hashcmp(head, abort_safety))
		return 1;

	error(_("You seem to have moved HEAD since the last 'am' failure.\n"
		"Not rewinding to ORIG_HEAD"));

	return 0;
}

/**
 * Aborts the current am session if it is safe to do so.
 */
static void am_abort(struct am_state *state)
{
	unsigned char curr_head[GIT_SHA1_RAWSZ], orig_head[GIT_SHA1_RAWSZ];
	int has_curr_head, has_orig_head;
	char *curr_branch;

	if (!safe_to_abort(state)) {
		am_destroy(state);
		return;
	}

	curr_branch = resolve_refdup("HEAD", 0, curr_head, NULL);
	has_curr_head = !is_null_sha1(curr_head);
	if (!has_curr_head)
		hashcpy(curr_head, EMPTY_TREE_SHA1_BIN);

	has_orig_head = !get_sha1("ORIG_HEAD", orig_head);
	if (!has_orig_head)
		hashcpy(orig_head, EMPTY_TREE_SHA1_BIN);

	clean_index(curr_head, orig_head);

	if (has_orig_head)
		update_ref("am --abort", "HEAD", orig_head,
				has_curr_head ? curr_head : NULL, 0,
				UPDATE_REFS_DIE_ON_ERR);
	else if (curr_branch)
		delete_ref(curr_branch, NULL, REF_NODEREF);

	free(curr_branch);
	am_destroy(state);
}

/**
 * parse_options() callback that validates and sets opt->value to the
 * PATCH_FORMAT_* enum value corresponding to `arg`.
