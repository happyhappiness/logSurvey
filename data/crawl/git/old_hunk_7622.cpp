	diff_populate_filespec(two, 0);
	lc_a = count_lines(one->data, one->size);
	lc_b = count_lines(two->data, two->size);
	printf("%s--- a/%s%s%s\n%s+++ b/%s%s%s\n%s@@ -",
	       metainfo, name_a, name_a_tab, reset,
	       metainfo, name_b, name_b_tab, reset, fraginfo);
	print_line_count(lc_a);
	printf(" +");
	print_line_count(lc_b);
