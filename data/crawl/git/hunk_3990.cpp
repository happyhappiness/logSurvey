 			     char **repo_abbrev)
 {
 	char buffer[1024];
-	FILE *f = (filename == NULL ? NULL : fopen(filename, "r"));
+	FILE *f;
+
+	if (!filename)
+		return 0;
+
+	f = fopen(filename, "r");
+	if (!f) {
+		if (errno == ENOENT)
+			return 0;
+		return error("unable to open mailmap at %s: %s",
+			     filename, strerror(errno));
+	}
 
-	if (f == NULL)
-		return 1;
 	while (fgets(buffer, sizeof(buffer), f) != NULL)
 		read_mailmap_line(map, buffer, repo_abbrev);
 	fclose(f);
