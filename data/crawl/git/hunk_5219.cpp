 	lc_a = count_lines(data_one, size_one);
 	lc_b = count_lines(data_two, size_two);
 	fprintf(o->file,
-		"%s--- %s%s%s\n%s+++ %s%s%s\n%s@@ -",
-		metainfo, a_name.buf, name_a_tab, reset,
-		metainfo, b_name.buf, name_b_tab, reset, fraginfo);
+		"%s%s--- %s%s%s\n%s%s+++ %s%s%s\n%s%s@@ -",
+		line_prefix, metainfo, a_name.buf, name_a_tab, reset,
+		line_prefix, metainfo, b_name.buf, name_b_tab, reset,
+		line_prefix, fraginfo);
 	print_line_count(o->file, lc_a);
 	fprintf(o->file, " +");
 	print_line_count(o->file, lc_b);
