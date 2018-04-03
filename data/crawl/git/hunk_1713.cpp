 
 	printf("There are only 'skip'ped commits left to test.\n"
 	       "The first %s commit could be any of:\n", term_bad);
-	print_commit_list(tried, "%s\n", "%s\n");
+
+	for ( ; tried; tried = tried->next)
+		printf("%s\n", oid_to_hex(&tried->item->object.oid));
+
 	if (bad)
 		printf("%s\n", oid_to_hex(bad));
 	printf("We cannot bisect more!\n");
