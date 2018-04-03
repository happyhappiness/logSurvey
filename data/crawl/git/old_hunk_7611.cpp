	const char *old = diff_get_color(color_diff, DIFF_FILE_OLD);
	const char *new = diff_get_color(color_diff, DIFF_FILE_NEW);
	const char *reset = diff_get_color(color_diff, DIFF_RESET);

	name_a += (*name_a == '/');
	name_b += (*name_b == '/');
	name_a_tab = strchr(name_a, ' ') ? "\t" : "";
	name_b_tab = strchr(name_b, ' ') ? "\t" : "";

	diff_populate_filespec(one, 0);
	diff_populate_filespec(two, 0);
	lc_a = count_lines(one->data, one->size);
	lc_b = count_lines(two->data, two->size);
	printf("%s--- %s%s%s%s\n%s+++ %s%s%s%s\n%s@@ -",
	       metainfo, o->a_prefix, name_a, name_a_tab, reset,
	       metainfo, o->b_prefix, name_b, name_b_tab, reset, fraginfo);
	print_line_count(lc_a);
	printf(" +");
	print_line_count(lc_b);
