 
 static void read_from_stdin(struct path_list *list)
 {
-	char buffer[1024];
-
-	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
-		char *bob;
-		if ((buffer[0] == 'A' || buffer[0] == 'a') &&
-				!prefixcmp(buffer + 1, "uthor: ") &&
-				(bob = strchr(buffer + 7, '<')) != NULL) {
-			char buffer2[1024], offset = 0;
-
-			if (map_email(&mailmap, bob + 1, buffer, sizeof(buffer)))
-				bob = buffer + strlen(buffer);
-			else {
-				offset = 8;
-				while (buffer + offset < bob &&
-				       isspace(bob[-1]))
-					bob--;
-			}
-
-			while (fgets(buffer2, sizeof(buffer2), stdin) &&
-					buffer2[0] != '\n')
-				; /* chomp input */
-			if (fgets(buffer2, sizeof(buffer2), stdin)) {
-				int l2 = strlen(buffer2);
-				int i;
-				for (i = 0; i < l2; i++)
-					if (!isspace(buffer2[i]))
-						break;
-				insert_author_oneline(list,
-						buffer + offset,
-						bob - buffer - offset,
-						buffer2 + i, l2 - i);
-			}
-		}
+	char author[1024], oneline[1024];
+
+	while (fgets(author, sizeof(author), stdin) != NULL) {
+		if (!(author[0] == 'A' || author[0] == 'a') ||
+		    prefixcmp(author + 1, "uthor: "))
+			continue;
+		while (fgets(oneline, sizeof(oneline), stdin) &&
+		       oneline[0] != '\n')
+			; /* discard headers */
+		while (fgets(oneline, sizeof(oneline), stdin) &&
+		       oneline[0] == '\n')
+			; /* discard blanks */
+		insert_one_record(list, author + 8, oneline);
 	}
 }
 
 static void get_from_rev(struct rev_info *rev, struct path_list *list)
 {
-	char scratch[1024];
 	struct commit *commit;
 
 	prepare_revision_walk(rev);
 	while ((commit = get_revision(rev)) != NULL) {
-		const char *author = NULL, *oneline, *buffer;
-		int authorlen = authorlen, onelinelen;
+		const char *author = NULL, *buffer;
 
-		/* get author and oneline */
-		for (buffer = commit->buffer; buffer && *buffer != '\0' &&
-				*buffer != '\n'; ) {
+		buffer = commit->buffer;
+		while (*buffer && *buffer != '\n') {
 			const char *eol = strchr(buffer, '\n');
 
 			if (eol == NULL)
 				eol = buffer + strlen(buffer);
 			else
 				eol++;
 
-			if (!prefixcmp(buffer, "author ")) {
-				char *bracket = strchr(buffer, '<');
-
-				if (bracket == NULL || bracket > eol)
-					die("Invalid commit buffer: %s",
-					    sha1_to_hex(commit->object.sha1));
-
-				if (map_email(&mailmap, bracket + 1, scratch,
-							sizeof(scratch))) {
-					author = scratch;
-					authorlen = strlen(scratch);
-				} else {
-					if (bracket[-1] == ' ')
-						bracket--;
-
-					author = buffer + 7;
-					authorlen = bracket - buffer - 7;
-				}
-			}
+			if (!prefixcmp(buffer, "author "))
+				author = buffer + 7;
 			buffer = eol;
 		}
-
-		if (author == NULL)
-			die ("Missing author: %s",
-					sha1_to_hex(commit->object.sha1));
-
-		if (buffer == NULL || *buffer == '\0') {
-			oneline = "<none>";
-			onelinelen = sizeof(oneline) + 1;
-		} else {
-			char *eol;
-
-			oneline = buffer + 1;
-			eol = strchr(oneline, '\n');
-			if (eol == NULL)
-				onelinelen = strlen(oneline);
-			else
-				onelinelen = eol - oneline;
-		}
-
-		insert_author_oneline(list,
-				author, authorlen, oneline, onelinelen);
+		if (!author)
+			die("Missing author: %s",
+			    sha1_to_hex(commit->object.sha1));
+		if (*buffer)
+			buffer++;
+		insert_one_record(list, author, !*buffer ? "<none>" : buffer);
 	}
-
 }
 
 static int parse_uint(char const **arg, int comma)