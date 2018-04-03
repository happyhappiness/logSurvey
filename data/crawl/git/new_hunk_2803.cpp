
static int sort_by_version(const void *a_, const void *b_)
{
	const struct ref_array_item *a = *((struct ref_array_item **)a_);
	const struct ref_array_item *b = *((struct ref_array_item **)b_);
	return versioncmp(a->refname, b->refname);
}

static int list_tags(struct ref_filter *filter, int sort)
{
	struct ref_array array;
	struct ref_filter_cbdata data;

	memset(&array, 0, sizeof(array));
	data.array = &array;
	data.filter = filter;

	if (filter->lines == -1)
		filter->lines = 0;

	for_each_tag_ref(show_reference, &data);
	if (sort) {
		int i;
		if ((sort & SORT_MASK) == VERCMP_SORT)
			qsort(array.items, array.nr,
			      sizeof(struct ref_array_item *), sort_by_version);
		if (sort & REVERSE_SORT)
			for (i = array.nr - 1; i >= 0; i--)
				printf("%s\n", array.items[i]->refname);
		else
			for (i = 0; i < array.nr; i++)
				printf("%s\n", array.items[i]->refname);
		ref_array_clear(&array);
	}
	return 0;
}
