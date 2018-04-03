		printf("\n");
}

static int update_index_refresh(int fd, struct lock_file *index_lock, int flags)
{
	if (!index_lock) {
		index_lock = xcalloc(1, sizeof(struct lock_file));
		fd = hold_locked_index(index_lock, 1);
	}

	refresh_index(&the_index, (flags), NULL, NULL,
		      _("Unstaged changes after reset:"));
	if (write_cache(fd, active_cache, active_nr) ||
			commit_locked_index(index_lock))
		return error ("Could not refresh index");
	return 0;
}

static void update_index_from_diff(struct diff_queue_struct *q,
