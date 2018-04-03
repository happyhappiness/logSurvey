	}
}

static void log_show_early(struct rev_info *revs, struct commit_list *list)
{
	int i = revs->early_output;

	sort_in_topological_order(&list, revs->lifo);
	while (list && i) {
		struct commit *commit = list->item;
		log_tree_commit(revs, commit);
		list = list->next;
		i--;
	}
}

static void early_output(int signal)
{
	show_early_output = log_show_early;
}

static void setup_early_output(struct rev_info *rev)
{
	struct sigaction sa;
	struct itimerval v;

	/*
	 * Set up the signal handler, minimally intrusively:
	 * we only set a single volatile integer word (not
	 * using sigatomic_t - trying to avoid unnecessary
	 * system dependencies and headers), and using
	 * SA_RESTART.
	 */
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = early_output;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGALRM, &sa, NULL);

	/*
	 * If we can get the whole output in less than a
	 * tenth of a second, don't even bother doing the
	 * early-output thing..
	 *
	 * This is a one-time-only trigger.
	 */
	memset(&v, 0, sizeof(v));
	v.it_value.tv_sec = 0;
	v.it_value.tv_usec = 100000;
	setitimer(ITIMER_REAL, &v, NULL);
}

static void finish_early_output(struct rev_info *rev)
{
	signal(SIGALRM, SIG_IGN);
	if (rev->shown_one) {
		rev->shown_one = 0;
		if (rev->commit_format != CMIT_FMT_ONELINE)
			putchar(rev->diffopt.line_termination);
	}
	printf("Final output:\n");
}

static int cmd_log_walk(struct rev_info *rev)
{
	struct commit *commit;

	if (rev->early_output)
		setup_early_output(rev);

	prepare_revision_walk(rev);

	if (rev->early_output)
		finish_early_output(rev);

	while ((commit = get_revision(rev)) != NULL) {
		log_tree_commit(rev, commit);
		if (!rev->reflog_info) {
