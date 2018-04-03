 		printf("------\n");
 	}
 
+	stringed = flags & BISECT_SHOW_STRINGED;
+
 	if (flags & BISECT_SHOW_TRIED)
-		show_tried_revs(tried, flags & BISECT_SHOW_STRINGED);
-	format = (flags & BISECT_SHOW_STRINGED) ?
-		"bisect_rev=%s &&\n"
-		"bisect_nr=%d &&\n"
-		"bisect_good=%d &&\n"
-		"bisect_bad=%d &&\n"
-		"bisect_all=%d &&\n"
-		"bisect_steps=%d\n"
-		:
-		"bisect_rev=%s\n"
-		"bisect_nr=%d\n"
-		"bisect_good=%d\n"
-		"bisect_bad=%d\n"
-		"bisect_all=%d\n"
-		"bisect_steps=%d\n";
-	printf(format,
-	       hex,
-	       cnt - 1,
-	       all - reaches - 1,
-	       reaches - 1,
-	       all,
-	       estimate_bisect_steps(all));
+		show_tried_revs(tried, stringed);
+
+	print_var_str("bisect_rev", hex, stringed);
+	print_var_int("bisect_nr", cnt - 1, stringed);
+	print_var_int("bisect_good", all - reaches - 1, stringed);
+	print_var_int("bisect_bad", reaches - 1, stringed);
+	print_var_int("bisect_all", all, stringed);
+	print_var_int("bisect_steps", estimate_bisect_steps(all), 0);
 
 	return 0;
 }