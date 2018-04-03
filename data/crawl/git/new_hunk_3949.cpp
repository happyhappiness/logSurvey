		printf("\n");
}

static void update_index_refresh(int flags)
{
	refresh_index(&the_index, (flags), NULL, NULL,
		      _("Unstaged changes after reset:"));
}

static void update_index_from_diff(struct diff_queue_struct *q,
