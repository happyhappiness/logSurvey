 	}
 
 	if (flags & BISECT_SHOW_TRIED)
-		show_tried_revs(tried);
-	printf("bisect_rev=%s\n"
-	       "bisect_nr=%d\n"
-	       "bisect_good=%d\n"
-	       "bisect_bad=%d\n"
-	       "bisect_all=%d\n"
-	       "bisect_steps=%d\n",
+		show_tried_revs(tried, flags & BISECT_SHOW_STRINGED);
+	format = (flags & BISECT_SHOW_STRINGED) ?
+		"bisect_rev=%s &&\n"
+		"bisect_nr=%d &&\n"
+		"bisect_good=%d &&\n"
+		"bisect_bad=%d &&\n"
+		"bisect_all=%d &&\n"
+		"bisect_steps=%d\n"
+		:
+		"bisect_rev=%s\n"
+		"bisect_nr=%d\n"
+		"bisect_good=%d\n"
+		"bisect_bad=%d\n"
+		"bisect_all=%d\n"
+		"bisect_steps=%d\n";
+	printf(format,
 	       hex,
 	       cnt - 1,
 	       all - reaches - 1,
