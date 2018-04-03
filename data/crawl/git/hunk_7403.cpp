 		while (fgets(oneline, sizeof(oneline), stdin) &&
 		       oneline[0] == '\n')
 			; /* discard blanks */
-		insert_one_record(list, author + 8, oneline);
+		insert_one_record(log, author + 8, oneline);
 	}
 }
 
-static void get_from_rev(struct rev_info *rev, struct path_list *list)
+void shortlog_add_commit(struct shortlog *log, struct commit *commit)
 {
-	struct commit *commit;
-
-	prepare_revision_walk(rev);
-	while ((commit = get_revision(rev)) != NULL) {
-		const char *author = NULL, *buffer;
+	const char *author = NULL, *buffer;
 
-		buffer = commit->buffer;
-		while (*buffer && *buffer != '\n') {
-			const char *eol = strchr(buffer, '\n');
+	buffer = commit->buffer;
+	while (*buffer && *buffer != '\n') {
+		const char *eol = strchr(buffer, '\n');
 
-			if (eol == NULL)
-				eol = buffer + strlen(buffer);
-			else
-				eol++;
+		if (eol == NULL)
+			eol = buffer + strlen(buffer);
+		else
+			eol++;
 
-			if (!prefixcmp(buffer, "author "))
-				author = buffer + 7;
-			buffer = eol;
-		}
-		if (!author)
-			die("Missing author: %s",
-			    sha1_to_hex(commit->object.sha1));
-		if (*buffer)
-			buffer++;
-		insert_one_record(list, author, !*buffer ? "<none>" : buffer);
+		if (!prefixcmp(buffer, "author "))
+			author = buffer + 7;
+		buffer = eol;
 	}
+	if (!author)
+		die("Missing author: %s",
+		    sha1_to_hex(commit->object.sha1));
+	if (*buffer)
+		buffer++;
+	insert_one_record(log, author, !*buffer ? "<none>" : buffer);
+}
+
+static void get_from_rev(struct rev_info *rev, struct shortlog *log)
+{
+	struct commit *commit;
+
+	if (prepare_revision_walk(rev))
+		die("revision walk setup failed");
+	while ((commit = get_revision(rev)) != NULL)
+		shortlog_add_commit(log, commit);
 }
 
 static int parse_uint(char const **arg, int comma)
