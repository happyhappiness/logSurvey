 	display_name(all_matches[0].name);
 	if (abbrev)
 		show_suffix(all_matches[0].depth, &cmit->object.oid);
-	if (dirty)
-		printf("%s", dirty);
+	if (suffix)
+		printf("%s", suffix);
 	printf("\n");
 
 	if (!last_one)
