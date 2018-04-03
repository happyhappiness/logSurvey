		wt_status_print_submodule_summary(s, 0);  /* staged */
		wt_status_print_submodule_summary(s, 1);  /* unstaged */
	}
	if (s->show_untracked_files)
		wt_status_print_other(s, &s->untracked, "Untracked", "add");
	else if (s->commitable)
		 fprintf(s->fp, "# Untracked files not listed (use -u option to show untracked files)\n");

	if (s->verbose)
