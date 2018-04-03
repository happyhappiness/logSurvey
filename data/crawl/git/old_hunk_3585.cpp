	char name[1];
} ref_cache, *submodule_ref_caches;

static void clear_packed_ref_cache(struct ref_cache *refs)
{
	if (refs->packed) {
		free_ref_entry(refs->packed->root);
		free(refs->packed);
		refs->packed = NULL;
