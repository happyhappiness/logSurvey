
/* Here come the merge functions */

static int reject_merge(struct cache_entry *ce)
{
	return error("Entry '%s' would be overwritten by merge. Cannot merge.",
		     ce->name);
}

static int same(struct cache_entry *a, struct cache_entry *b)
