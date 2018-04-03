	DIFF_QUEUE_CLEAR(src);
}

static void queue_diffs(struct diff_options *opt,
			struct diff_queue_struct *queue,
			struct commit *commit, struct commit *parent)
{
