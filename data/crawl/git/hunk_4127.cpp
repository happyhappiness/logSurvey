 	int key_len = strlen(key);
 	const char *line = commit->buffer;
 
-	for (;;) {
+	while (line) {
 		const char *eol = strchr(line, '\n'), *next;
 
 		if (line == eol)
 			return NULL;
 		if (!eol) {
+			warning("malformed commit (header is missing newline): %s",
+				sha1_to_hex(commit->object.sha1));
 			eol = line + strlen(line);
 			next = NULL;
 		} else
