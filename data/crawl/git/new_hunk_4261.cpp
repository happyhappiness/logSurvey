
/*
 * Called by resolve_gitlink_ref_recursive() after it failed to read
 * from the loose refs in ref_cache refs. Find <refname> in the
 * packed-refs file for the submodule.
 */
static int resolve_gitlink_packed_ref(struct ref_cache *refs,
				      const char *refname, unsigned char *sha1)
{
	struct ref_entry *ref;
	struct ref_array *array = get_packed_refs(refs);

	ref = search_ref_array(array, refname);
	if (ref == NULL)
		return -1;

	memcpy(sha1, ref->sha1, 20);
	return 0;
}

static int resolve_gitlink_ref_recursive(struct ref_cache *refs,
					 char *name, int pathlen,
					 const char *refname, unsigned char *sha1,
					 int recursion)
{
