	strbuf_release(&newsection);
}

static int opt_parse_with_commit(const struct option *opt, const char *arg, int unset)
{
	unsigned char sha1[20];
	struct commit *commit;

	if (!arg)
		return -1;
	if (get_sha1(arg, sha1))
		die("malformed object name %s", arg);
	commit = lookup_commit_reference(sha1);
	if (!commit)
		die("no such commit %s", arg);
	commit_list_insert(commit, opt->value);
	return 0;
}

static int opt_parse_merge_filter(const struct option *opt, const char *arg, int unset)
{
	merge_filter = ((opt->long_name[0] == 'n')
