	return contains_recurse(candidate, want);
}

static int show_reference(const char *refname, const unsigned char *sha1,
			  int flag, void *cb_data)
{
	struct tag_filter *filter = cb_data;

	if (match_pattern(filter->patterns, refname)) {
		int i;
		unsigned long size;
		enum object_type type;
		char *buf, *sp, *eol;
		size_t len;

		if (filter->with_commit) {
			struct commit *commit;

