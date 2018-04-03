
	strbuf_release(&sb);

	if (use_editor) {
		if (in_merge)
			fprintf(fp,
				"#\n"
				"# It looks like you may be committing a MERGE.\n"
				"# If this is not correct, please remove the file\n"
				"#	%s\n"
				"# and try again.\n"
				"#\n",
				git_path("MERGE_HEAD"));

		fprintf(fp,
			"\n"
			"# Please enter the commit message for your changes.\n"
			"# (Comment lines starting with '#' will ");
		if (cleanup_mode == CLEANUP_ALL)
			fprintf(fp, "not be included)\n");
		else /* CLEANUP_SPACE, that is. */
			fprintf(fp, "be kept.\n"
				"# You can remove them yourself if you want to)\n");
		if (only_include_assumed)
			fprintf(fp, "# %s\n", only_include_assumed);

		saved_color_setting = wt_status_use_color;
		wt_status_use_color = 0;
		commitable = run_status(fp, index_file, prefix, 1);
		wt_status_use_color = saved_color_setting;
	} else {
		struct rev_info rev;
		unsigned char sha1[20];
		const char *parent = "HEAD";

		if (!active_nr && read_cache() < 0)
			die("Cannot read index");

		if (amend)
			parent = "HEAD^1";

		if (get_sha1(parent, sha1))
			commitable = !!active_nr;
		else {
			init_revisions(&rev, "");
			rev.abbrev = 0;
			setup_revisions(0, NULL, &rev, parent);
			DIFF_OPT_SET(&rev.diffopt, QUIET);
			DIFF_OPT_SET(&rev.diffopt, EXIT_WITH_STATUS);
			run_diff_index(&rev, 1 /* cached */);

			commitable = !!DIFF_OPT_TST(&rev.diffopt, HAS_CHANGES);
		}
	}

	fclose(fp);

	if (!commitable && !in_merge && !allow_empty &&
	    !(amend && is_a_merge(head_sha1))) {
		run_status(stdout, index_file, prefix, 0);
		unlink(commit_editmsg);
		return 0;
	}

	/*
	 * Re-read the index as pre-commit hook could have updated it,
	 * and write it out as a tree.  We must do this before we invoke
	 * the editor and after we invoke run_status above.
	 */
	discard_cache();
	read_cache_from(index_file);
	if (!active_cache_tree)
		active_cache_tree = cache_tree();
	if (cache_tree_update(active_cache_tree,
			      active_cache, active_nr, 0, 0) < 0) {
		error("Error building trees");
		return 0;
	}

	if (use_editor) {
		char index[PATH_MAX];
		const char *env[2] = { index, NULL };
		snprintf(index, sizeof(index), "GIT_INDEX_FILE=%s", index_file);
		launch_editor(git_path(commit_editmsg), NULL, env);
	}

	if (!no_verify &&
	    run_hook(index_file, "commit-msg", git_path(commit_editmsg), NULL)) {
		return 0;
	}

	return 1;
}

/*
