int filter_refs(struct ref_array *array, struct ref_filter *filter, unsigned int type)
{
	struct ref_filter_cbdata ref_cbdata;
	int ret = 0;

	ref_cbdata.array = array;
	ref_cbdata.filter = filter;

	/*  Simple per-ref filtering */
	if (type & (FILTER_REFS_ALL | FILTER_REFS_INCLUDE_BROKEN))
		ret = for_each_rawref(ref_filter_handler, &ref_cbdata);
	else if (type & FILTER_REFS_ALL)
		ret = for_each_ref(ref_filter_handler, &ref_cbdata);
	else if (type)
		die("filter_refs: invalid type");

	/*  Filters that need revision walking */
	if (filter->merge_commit)
		do_merge_filter(&ref_cbdata);

	return ret;
}

static int cmp_ref_sorting(struct ref_sorting *s, struct ref_array_item *a, struct ref_array_item *b)
