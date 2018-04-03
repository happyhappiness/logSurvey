	return 0;
}

static int unpack_failed(struct unpack_trees_options *o, const char *message)
{
	discard_index(&o->result);
	if (!o->gently) {
		if (message)
			return error("%s", message);
		return -1;
	}
	return -1;
}

static int unpack_callback(int n, unsigned long mask, unsigned long dirmask, struct name_entry *names, struct traverse_info *info)
{
	struct cache_entry *src[MAX_UNPACK_TREES + 1] = { NULL, };
