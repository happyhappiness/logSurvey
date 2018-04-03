		break;
	}
}

/**
 * Returns 1 if there are unstaged changes, 0 otherwise.
 */
static int has_unstaged_changes(void)
{
	struct rev_info rev_info;
	int result;

	init_revisions(&rev_info, NULL);
	DIFF_OPT_SET(&rev_info.diffopt, IGNORE_SUBMODULES);
	DIFF_OPT_SET(&rev_info.diffopt, QUICK);
	diff_setup_done(&rev_info.diffopt);
	result = run_diff_files(&rev_info, 0);
	return diff_result_code(&rev_info.diffopt, result);
}

/**
 * Returns 1 if there are uncommitted changes, 0 otherwise.
 */
static int has_uncommitted_changes(void)
{
	struct rev_info rev_info;
	int result;

	if (is_cache_unborn())
		return 0;

	init_revisions(&rev_info, NULL);
	DIFF_OPT_SET(&rev_info.diffopt, IGNORE_SUBMODULES);
	DIFF_OPT_SET(&rev_info.diffopt, QUICK);
	add_head_to_pending(&rev_info);
	diff_setup_done(&rev_info.diffopt);
	result = run_diff_index(&rev_info, 1);
	return diff_result_code(&rev_info.diffopt, result);
}

/**
 * If the work tree has unstaged or uncommitted changes, dies with the
 * appropriate message.
 */
int require_clean_work_tree(const char *action, const char *hint, int gently)
{
	struct lock_file *lock_file = xcalloc(1, sizeof(*lock_file));
	int err = 0;

	hold_locked_index(lock_file, 0);
	refresh_cache(REFRESH_QUIET);
	update_index_if_able(&the_index, lock_file);
	rollback_lock_file(lock_file);

	if (has_unstaged_changes()) {
		/* TRANSLATORS: the action is e.g. "pull with rebase" */
		error(_("Cannot %s: You have unstaged changes."), _(action));
		err = 1;
	}

	if (has_uncommitted_changes()) {
		if (err)
			error(_("Additionally, your index contains uncommitted changes."));
		else
			error(_("Cannot %s: Your index contains uncommitted changes."),
			      _(action));
		err = 1;
	}

	if (err) {
		if (hint)
			error("%s", hint);
		if (!gently)
			exit(128);
	}

	return err;
}
