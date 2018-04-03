static int rename_ref_available(const char *oldname, const char *newname)
{
	struct string_list skip = STRING_LIST_INIT_NODUP;
	int ret;

	string_list_insert(&skip, oldname);
	ret = !verify_refname_available(newname, NULL, &skip,
					get_packed_refs(&ref_cache))
		&& !verify_refname_available(newname, NULL, &skip,
					     get_loose_refs(&ref_cache));
	string_list_clear(&skip, 0);
	return ret;
}
