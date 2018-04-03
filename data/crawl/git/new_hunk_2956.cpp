}

/**
 * Applies current patch with git-apply. Returns 0 on success, -1 otherwise. If
 * `index_file` is not NULL, the patch will be applied to that index.
 */
static int run_apply(const struct am_state *state, const char *index_file)
{
	struct child_process cp = CHILD_PROCESS_INIT;

	cp.git_cmd = 1;

	if (index_file)
		argv_array_pushf(&cp.env_array, "GIT_INDEX_FILE=%s", index_file);

	/*
	 * If we are allowed to fall back on 3-way merge, don't give false
	 * errors during the initial attempt.
	 */
	if (state->threeway && !index_file) {
		cp.no_stdout = 1;
		cp.no_stderr = 1;
	}

	argv_array_push(&cp.args, "apply");

	if (index_file)
		argv_array_push(&cp.args, "--cached");
	else
		argv_array_push(&cp.args, "--index");

	argv_array_push(&cp.args, am_path(state, "patch"));

	if (run_command(&cp))
		return -1;

	/* Reload index as git-apply will have modified it. */
	discard_cache();
	read_cache_from(index_file ? index_file : get_index_file());

	return 0;
}

/**
 * Builds an index that contains just the blobs needed for a 3way merge.
 */
static int build_fake_ancestor(const struct am_state *state, const char *index_file)
{
	struct child_process cp = CHILD_PROCESS_INIT;

	cp.git_cmd = 1;
	argv_array_push(&cp.args, "apply");
	argv_array_pushf(&cp.args, "--build-fake-ancestor=%s", index_file);
	argv_array_push(&cp.args, am_path(state, "patch"));

	if (run_command(&cp))
		return -1;

	return 0;
}

/**
 * Attempt a threeway merge, using index_path as the temporary index.
 */
static int fall_back_threeway(const struct am_state *state, const char *index_path)
{
	unsigned char orig_tree[GIT_SHA1_RAWSZ], his_tree[GIT_SHA1_RAWSZ],
		      our_tree[GIT_SHA1_RAWSZ];
	const unsigned char *bases[1] = {orig_tree};
	struct merge_options o;
	struct commit *result;
	char *his_tree_name;

	if (get_sha1("HEAD", our_tree) < 0)
		hashcpy(our_tree, EMPTY_TREE_SHA1_BIN);

	if (build_fake_ancestor(state, index_path))
		return error("could not build fake ancestor");

	discard_cache();
	read_cache_from(index_path);

	if (write_index_as_tree(orig_tree, &the_index, index_path, 0, NULL))
		return error(_("Repository lacks necessary blobs to fall back on 3-way merge."));

	say(state, stdout, _("Using index info to reconstruct a base tree..."));

	if (!state->quiet) {
		/*
		 * List paths that needed 3-way fallback, so that the user can
		 * review them with extra care to spot mismerges.
		 */
		struct rev_info rev_info;
		const char *diff_filter_str = "--diff-filter=AM";

		init_revisions(&rev_info, NULL);
		rev_info.diffopt.output_format = DIFF_FORMAT_NAME_STATUS;
		diff_opt_parse(&rev_info.diffopt, &diff_filter_str, 1);
		add_pending_sha1(&rev_info, "HEAD", our_tree, 0);
		diff_setup_done(&rev_info.diffopt);
		run_diff_index(&rev_info, 1);
	}

	if (run_apply(state, index_path))
		return error(_("Did you hand edit your patch?\n"
				"It does not apply to blobs recorded in its index."));

	if (write_index_as_tree(his_tree, &the_index, index_path, 0, NULL))
		return error("could not write tree");

	say(state, stdout, _("Falling back to patching base and 3-way merge..."));

	discard_cache();
	read_cache();

	/*
	 * This is not so wrong. Depending on which base we picked, orig_tree
	 * may be wildly different from ours, but his_tree has the same set of
	 * wildly different changes in parts the patch did not touch, so
	 * recursive ends up canceling them, saying that we reverted all those
	 * changes.
	 */

	init_merge_options(&o);

	o.branch1 = "HEAD";
	his_tree_name = xstrfmt("%.*s", linelen(state->msg), state->msg);
	o.branch2 = his_tree_name;

	if (state->quiet)
		o.verbosity = 0;

	if (merge_recursive_generic(&o, our_tree, his_tree, 1, bases, &result)) {
		free(his_tree_name);
		return error(_("Failed to merge in the changes."));
	}

	free(his_tree_name);
	return 0;
}

