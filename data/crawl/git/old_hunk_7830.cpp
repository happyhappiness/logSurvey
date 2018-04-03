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
