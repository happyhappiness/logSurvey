static const char * const git_replace_usage[] = {
	N_("git replace [-f] <object> <replacement>"),
	N_("git replace -d <object>..."),
	N_("git replace -l [<pattern>]"),
	NULL
};

static int show_reference(const char *refname, const unsigned char *sha1,
			  int flag, void *cb_data)
{
	const char *pattern = cb_data;

	if (!fnmatch(pattern, refname, 0))
		printf("%s\n", refname);

	return 0;
}

static int list_replace_refs(const char *pattern)
{
	if (pattern == NULL)
		pattern = "*";

	for_each_replace_ref(show_reference, (void *) pattern);

	return 0;
}
