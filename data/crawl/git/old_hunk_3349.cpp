	return 0;
}

static int list_tags(const char **patterns, int lines,
			struct commit_list *with_commit)
{
	struct tag_filter filter;

	filter.patterns = patterns;
	filter.lines = lines;
	filter.with_commit = with_commit;

	for_each_tag_ref(show_reference, (void *) &filter);

	return 0;
}

