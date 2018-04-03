		remote_prefix = "remotes/";

	memset(&array, 0, sizeof(array));

	verify_ref_format("%(refname)%(symref)");
	filter_refs(&array, filter, filter->kind | FILTER_REFS_INCLUDE_BROKEN);

	if (filter->verbose)
		maxwidth = calc_maxwidth(&array, strlen(remote_prefix));

	/*
	 * If no sorting parameter is given then we default to sorting
	 * by 'refname'. This would give us an alphabetically sorted
	 * array with the 'HEAD' ref at the beginning followed by
	 * local branches 'refs/heads/...' and finally remote-tacking
	 * branches 'refs/remotes/...'.
	 */
	if (!sorting)
		sorting = ref_default_sorting();
	ref_array_sort(sorting, &array);

	for (i = 0; i < array.nr; i++)
		format_and_print_ref_item(array.items[i], maxwidth, filter, remote_prefix);

	ref_array_clear(&array);
}
