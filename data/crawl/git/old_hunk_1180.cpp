 */
static void add_packed_ref(const char *refname, const unsigned char *sha1)
{
	struct packed_ref_cache *packed_ref_cache =
		get_packed_ref_cache(&ref_store);

	if (!packed_ref_cache->lock)
		die("internal error: packed refs not locked");
