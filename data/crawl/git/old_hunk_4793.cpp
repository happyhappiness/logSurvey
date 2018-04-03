		if (s->show_ignored_files)
			wt_status_print_other(s, &s->ignored, "Ignored", "add -f");
	} else if (s->commitable)
		fprintf(s->fp, "# Untracked files not listed%s\n",
			advice_status_hints
			? " (use -u option to show untracked files)" : "");

	if (s->verbose)
		wt_status_print_verbose(s);
	if (!s->commitable) {
		if (s->amend)
			fprintf(s->fp, "# No changes\n");
		else if (s->nowarn)
			; /* nothing */
		else if (s->workdir_dirty)