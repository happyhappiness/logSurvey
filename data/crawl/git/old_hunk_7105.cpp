	wt_status_print_changed(s);
	if (wt_status_submodule_summary)
		wt_status_print_submodule_summary(s);
	wt_status_print_untracked(s);

	if (s->verbose && !s->is_initial)
		wt_status_print_verbose(s);
