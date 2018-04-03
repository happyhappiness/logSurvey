	return 0;
}

struct blame_entry *blame_entry_prepend(struct blame_entry *head,
					long start, long end,
					struct blame_origin *o)