 * Create a new submodule ref cache and add it to the internal
 * set of caches.
 */
static struct files_ref_store *create_ref_store(const char *submodule)
{
	struct files_ref_store *refs;
	if (!submodule)
		submodule = "";
	FLEX_ALLOC_STR(refs, name, submodule);
	refs->next = submodule_ref_stores;
	submodule_ref_stores = refs;
	return refs;
}

static struct files_ref_store *lookup_ref_store(const char *submodule)
{
	struct files_ref_store *refs;

	if (!submodule || !*submodule)
		return &ref_store;

	for (refs = submodule_ref_stores; refs; refs = refs->next)
		if (!strcmp(submodule, refs->name))
			return refs;
	return NULL;
}

/*
 * Return a pointer to a files_ref_store for the specified submodule. For
 * the main repository, use submodule==NULL; such a call cannot fail.
 * For a submodule, the submodule must exist and be a nonbare
 * repository, otherwise return NULL.
 *
 * The returned structure will be allocated and initialized but not
 * necessarily populated; it should not be freed.
 */
static struct files_ref_store *get_ref_store(const char *submodule)
{
	struct files_ref_store *refs = lookup_ref_store(submodule);

	if (!refs) {
		struct strbuf submodule_sb = STRBUF_INIT;

		strbuf_addstr(&submodule_sb, submodule);
		if (is_nonbare_repository_dir(&submodule_sb))
			refs = create_ref_store(submodule);
		strbuf_release(&submodule_sb);
	}

	return refs;
}

/* The length of a peeled reference line in packed-refs, including EOL: */
