 	char author[1024], oneline[1024];
 
 	while (fgets(author, sizeof(author), stdin) != NULL) {
-		if (!(author[0] == 'A' || author[0] == 'a') ||
-		    !starts_with(author + 1, "uthor: "))
+		const char *v;
+		if (!skip_prefix(author, "Author: ", &v) &&
+		    !skip_prefix(author, "author ", &v))
 			continue;
 		while (fgets(oneline, sizeof(oneline), stdin) &&
 		       oneline[0] != '\n')
 			; /* discard headers */
 		while (fgets(oneline, sizeof(oneline), stdin) &&
 		       oneline[0] == '\n')
 			; /* discard blanks */
-		insert_one_record(log, author + 8, oneline);
+		insert_one_record(log, v, oneline);
 	}
 }
 
