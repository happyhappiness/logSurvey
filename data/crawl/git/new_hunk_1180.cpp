 */
static void add_packed_ref(const char *refname, const unsigned char *sha1)
{
	struct files_ref_store *refs =
		get_files_ref_store(NULL, "add_packed_ref");
	struct packed_ref_cache *packed_ref_cache = get_packed_ref_cache(refs);

	if (!packed_ref_cache->lock)
		die("internal error: packed refs not locked");
