	return 1;
}

static void close_pack(struct packed_git *p)
{
	close_pack_windows(p);
	close_pack_fd(p);
	close_pack_index(p);
}

void close_all_packs(void)
{
	struct packed_git *p;

	for (p = packed_git; p; p = p->next)
		if (p->do_not_close)
			die("BUG! Want to close pack marked 'do-not-close'");
		else
			close_pack(p);
}


/*
 * The LRU pack is the one with the oldest MRU window, preferring packs
 * with no used windows, or the oldest mtime if it has no windows allocated.
