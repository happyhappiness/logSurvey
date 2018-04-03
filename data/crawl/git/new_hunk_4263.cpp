	qsort(array->refs, array->nr, sizeof(*array->refs), ref_entry_cmp);

	/* Remove any duplicates from the ref_array */
	i = 0;
	for (j = 1; j < array->nr; j++) {
		if (is_dup_ref(array->refs[i], array->refs[j])) {
			free(array->refs[j]);
			continue;
		}
		array->refs[++i] = array->refs[j];
	}
	array->nr = i + 1;
}