 
 	display_name(all_matches[0].name);
 	if (abbrev)
-		printf("-%d-g%s", all_matches[0].depth,
-		       find_unique_abbrev(cmit->object.sha1, abbrev));
+		show_suffix(all_matches[0].depth, cmit->object.sha1);
 	printf("\n");
 
 	if (!last_one)