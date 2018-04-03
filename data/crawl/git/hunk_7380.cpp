 				sha1_to_hex(gave_up_on->object.sha1));
 		}
 	}
-	if (abbrev == 0)
-		printf("%s\n", all_matches[0].name->path );
-	else
-		printf("%s-%d-g%s\n", all_matches[0].name->path,
-		       all_matches[0].depth,
+
+	display_name(all_matches[0].name);
+	if (abbrev)
+		printf("-%d-g%s", all_matches[0].depth,
 		       find_unique_abbrev(cmit->object.sha1, abbrev));
+	printf("\n");
 
 	if (!last_one)
 		clear_commit_marks(cmit, -1);