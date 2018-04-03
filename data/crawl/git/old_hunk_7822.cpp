		printf("\n");
}

static int update_index_refresh(void)
{
	const char *argv_update_index[] = {"update-index", "--refresh", NULL};
	return run_command_v_opt(argv_update_index, RUN_GIT_CMD);
}

struct update_cb_data {
	int index_fd;
	struct lock_file *lock;
	int exit_code;
};

static void update_index_from_diff(struct diff_queue_struct *q,
		struct diff_options *opt, void *data)
{
	int i;
	struct update_cb_data *cb = data;

	/* do_diff_cache() mangled the index */
	discard_cache();
	read_cache();

	for (i = 0; i < q->nr; i++) {
