	return sort_ref_list(list);
}

static struct ref_list *get_loose_refs(void)
{
	if (!cached_refs.did_loose) {
