	NULL
};

static unsigned int colopts;

static int list_tags(struct ref_filter *filter, struct ref_sorting *sorting)
{
	struct ref_array array;
	char *format, *to_free = NULL;
	int i;

	memset(&array, 0, sizeof(array));

	if (filter->lines == -1)
		filter->lines = 0;

	if (filter->lines) {
		to_free = xstrfmt("%s %%(contents:lines=%d)",
				 "%(align:15)%(refname:short)%(end)", filter->lines);
		format = to_free;
	} else
		format = "%(refname:short)";

	verify_ref_format(format);
	filter_refs(&array, filter, FILTER_REFS_TAGS);
	ref_array_sort(sorting, &array);

	for (i = 0; i < array.nr; i++)
		show_ref_array_item(array.items[i], format, 0);
	ref_array_clear(&array);
	free(to_free);

	return 0;
}

