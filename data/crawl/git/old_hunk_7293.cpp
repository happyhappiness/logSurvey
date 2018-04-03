	diff_populate_filespec(two, 0);
	lc_a = count_lines(one->data, one->size);
	lc_b = count_lines(two->data, two->size);
	printf("%s--- %s%s%s\n%s+++ %s%s%s\n%s@@ -",
	       metainfo, a_name.buf, name_a_tab, reset,
	       metainfo, b_name.buf, name_b_tab, reset, fraginfo);
	print_line_count(lc_a);
	printf(" +");
	print_line_count(lc_b);
	printf(" @@%s\n", reset);
	if (lc_a)
		copy_file_with_prefix('-', one->data, one->size, old, reset);
	if (lc_b)
		copy_file_with_prefix('+', two->data, two->size, new, reset);
}

static int fill_mmfile(mmfile_t *mf, struct diff_filespec *one)
