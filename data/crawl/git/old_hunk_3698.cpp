		return DIFF_STATUS_MODIFIED;
}

static void update_callback(struct diff_queue_struct *q,
			    struct diff_options *opt, void *cbdata)
{
