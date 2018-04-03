	struct rev_info rev;
	struct strbuf out = STRBUF_INIT;
	struct commit_list *j;
	struct pretty_print_context ctx = {0};

	printf(_("Squash commit -- not updating HEAD\n"));

	init_revisions(&rev, NULL);
	rev.ignore_merges = 1;
