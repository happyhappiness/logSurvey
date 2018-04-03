	struct ref_filter_cbdata *ref_cbdata = cb_data;
	struct ref_filter *filter = ref_cbdata->filter;
	struct ref_array_item *ref;
	struct commit *commit = NULL;

	if (flag & REF_BAD_NAME) {
		warning("ignoring ref with broken name %s", refname);
