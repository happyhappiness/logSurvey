 static int tail_match(const char **pattern, const char *path)
 {
 	const char *p;
-	char pathbuf[PATH_MAX];
+	char *pathbuf;
 
 	if (!pattern)
 		return 1; /* no restriction */
 
-	if (snprintf(pathbuf, sizeof(pathbuf), "/%s", path) > sizeof(pathbuf))
-		return error("insanely long ref %.*s...", 20, path);
+	pathbuf = xstrfmt("/%s", path);
 	while ((p = *(pattern++)) != NULL) {
-		if (!wildmatch(p, pathbuf, 0, NULL))
+		if (!wildmatch(p, pathbuf, 0, NULL)) {
+			free(pathbuf);
 			return 1;
+		}
 	}
+	free(pathbuf);
 	return 0;
 }
 
