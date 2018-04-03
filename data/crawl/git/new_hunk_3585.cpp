	char name[1];
} ref_cache, *submodule_ref_caches;

/* Lock used for the main packed-refs file: */
static struct lock_file packlock;

static void clear_packed_ref_cache(struct ref_cache *refs)
{
	if (refs->packed) {
		if (refs->packed->lock)
			die("internal error: packed-ref cache cleared while locked");
		free_ref_entry(refs->packed->root);
		free(refs->packed);
		refs->packed = NULL;
