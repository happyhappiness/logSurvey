 
 static void print_new_head_line(struct commit *commit)
 {
-	const char *hex, *dots = "...", *body;
+	const char *hex, *body;
 
 	hex = find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV);
-	if (!hex) {
-		hex = sha1_to_hex(commit->object.sha1);
-		dots = "";
-	}
-	printf("HEAD is now at %s%s", hex, dots);
+	printf("HEAD is now at %s", hex);
 	body = strstr(commit->buffer, "\n\n");
 	if (body) {
 		const char *eol;
