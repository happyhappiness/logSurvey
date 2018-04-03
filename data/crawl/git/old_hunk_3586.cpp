
void add_packed_ref(const char *refname, const unsigned char *sha1)
{
	add_ref(get_packed_refs(&ref_cache),
		create_ref_entry(refname, sha1, REF_ISPACKED, 1));
}

