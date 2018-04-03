 
 	diff_populate_filespec(one, 0);
 	diff_populate_filespec(two, 0);
-	lc_a = count_lines(one->data, one->size);
-	lc_b = count_lines(two->data, two->size);
+	if (textconv_one) {
+		data_one = run_textconv(textconv_one, one, &size_one);
+		if (!data_one)
+			die("unable to read files to diff");
+	}
+	else {
+		data_one = one->data;
+		size_one = one->size;
+	}
+	if (textconv_two) {
+		data_two = run_textconv(textconv_two, two, &size_two);
+		if (!data_two)
+			die("unable to read files to diff");
+	}
+	else {
+		data_two = two->data;
+		size_two = two->size;
+	}
+
+	lc_a = count_lines(data_one, size_one);
+	lc_b = count_lines(data_two, size_two);
 	fprintf(o->file,
 		"%s--- %s%s%s\n%s+++ %s%s%s\n%s@@ -",
 		metainfo, a_name.buf, name_a_tab, reset,
