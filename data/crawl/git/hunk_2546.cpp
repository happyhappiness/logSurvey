 
 	display_name(all_matches[0].name);
 	if (abbrev)
-		show_suffix(all_matches[0].depth, cmit->object.sha1);
+		show_suffix(all_matches[0].depth, get_object_hash(cmit->object));
 	if (dirty)
 		printf("%s", dirty);
 	printf("\n");
