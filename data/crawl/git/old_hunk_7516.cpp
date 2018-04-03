
	strbuf_release(&sb);

	if (!use_editor) {
		struct rev_info rev;
		unsigned char sha1[20];
		const char *parent = "HEAD";

		fclose(fp);

		if (!active_nr && read_cache() < 0)
			die("Cannot read index");

		if (amend)
			parent = "HEAD^1";

		if (get_sha1(parent, sha1))
			return !!active_nr;

		init_revisions(&rev, "");
		rev.abbrev = 0;
		setup_revisions(0, NULL, &rev, parent);
		DIFF_OPT_SET(&rev.diffopt, QUIET);
		DIFF_OPT_SET(&rev.diffopt, EXIT_WITH_STATUS);
		run_diff_index(&rev, 1 /* cached */);

		return !!DIFF_OPT_TST(&rev.diffopt, HAS_CHANGES);
	}

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

	fclose(fp);

	return commitable;
}

/*
