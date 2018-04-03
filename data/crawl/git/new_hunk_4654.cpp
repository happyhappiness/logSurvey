	commit_style = COMMIT_PARTIAL;

	if (in_merge)
		die(_("cannot do a partial commit during a merge."));

	memset(&partial, 0, sizeof(partial));
	partial.strdup_strings = 1;
