	return 0;
}

struct expand_data {
	unsigned char sha1[20];
	enum object_type type;
	unsigned long size;

	/*
	 * If mark_query is true, we do not expand anything, but rather
	 * just mark the object_info with items we wish to query.
	 */
	int mark_query;

	/*
	 * After a mark_query run, this object_info is set up to be
	 * passed to sha1_object_info_extended. It will point to the data
	 * elements above, so you can retrieve the response from there.
	 */
	struct object_info info;
};

static int is_atom(const char *atom, const char *s, int slen)
{
	int alen = strlen(atom);
	return alen == slen && !memcmp(atom, s, alen);
}

static void expand_atom(struct strbuf *sb, const char *atom, int len,
			void *vdata)
{
	struct expand_data *data = vdata;

	if (is_atom("objectname", atom, len)) {
		if (!data->mark_query)
			strbuf_addstr(sb, sha1_to_hex(data->sha1));
	} else if (is_atom("objecttype", atom, len)) {
		if (!data->mark_query)
			strbuf_addstr(sb, typename(data->type));
	} else if (is_atom("objectsize", atom, len)) {
		if (data->mark_query)
			data->info.sizep = &data->size;
		else
			strbuf_addf(sb, "%lu", data->size);
	} else
		die("unknown format element: %.*s", len, atom);
}

static size_t expand_format(struct strbuf *sb, const char *start, void *data)
{
	const char *end;

	if (*start != '(')
		return 0;
	end = strchr(start + 1, ')');
	if (!end)
		die("format element '%s' does not end in ')'", start);

	expand_atom(sb, start + 1, end - start - 1, data);

	return end - start + 1;
}

static void print_object_or_die(int fd, const unsigned char *sha1,
				enum object_type type, unsigned long size)
{
