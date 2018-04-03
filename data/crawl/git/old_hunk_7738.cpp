static void wt_status_print_verbose(struct wt_status *s)
{
	struct rev_info rev;
	init_revisions(&rev, NULL);
	setup_revisions(0, NULL, &rev, s->reference);
	rev.diffopt.output_format |= DIFF_FORMAT_PATCH;
	rev.diffopt.detect_rename = 1;
	wt_read_cache(s);
	run_diff_index(&rev, 1);
}

void wt_status_print(struct wt_status *s)