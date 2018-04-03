	diff_populate_filespec(two, 0);
	lc_a = count_lines(one->data, one->size);
	lc_b = count_lines(two->data, two->size);
	printf("%s--- %s%s%s%s\n%s+++ %s%s%s%s\n%s@@ -",
	       metainfo, o->a_prefix, name_a, name_a_tab, reset,
	       metainfo, o->b_prefix, name_b, name_b_tab, reset, fraginfo);
	print_line_count(lc_a);
	printf(" +");
	print_line_count(lc_b);
