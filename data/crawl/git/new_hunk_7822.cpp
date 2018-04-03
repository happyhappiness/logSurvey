		printf("\n");
}

static int update_index_refresh(int fd, struct lock_file *index_lock)
{
	int result;

	if (!index_lock) {
		index_lock = xcalloc(1, sizeof(struct lock_file));
		fd = hold_locked_index(index_lock, 1);
	}

	if (read_cache() < 0)
		return error("Could not read index");
	result = refresh_cache(0) ? 1 : 0;
	if (write_cache(fd, active_cache, active_nr) ||
			close(fd) ||
			commit_locked_index(index_lock))
		return error ("Could not refresh index");
	return result;
}

static void update_index_from_diff(struct diff_queue_struct *q,
		struct diff_options *opt, void *data)
{
	int i;
	int *discard_flag = data;

	/* do_diff_cache() mangled the index */
	discard_cache();
	*discard_flag = 1;
	read_cache();

	for (i = 0; i < q->nr; i++) {
