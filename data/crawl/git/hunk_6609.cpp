 	free(ref_git_copy);
 }
 
-static void copy_or_link_directory(char *src, char *dest)
+static void copy_or_link_directory(struct strbuf *src, struct strbuf *dest)
 {
 	struct dirent *de;
 	struct stat buf;
 	int src_len, dest_len;
 	DIR *dir;
 
-	dir = opendir(src);
+	dir = opendir(src->buf);
 	if (!dir)
-		die("failed to open %s\n", src);
+		die("failed to open %s\n", src->buf);
 
-	if (mkdir(dest, 0777)) {
+	if (mkdir(dest->buf, 0777)) {
 		if (errno != EEXIST)
-			die("failed to create directory %s\n", dest);
-		else if (stat(dest, &buf))
-			die("failed to stat %s\n", dest);
+			die("failed to create directory %s\n", dest->buf);
+		else if (stat(dest->buf, &buf))
+			die("failed to stat %s\n", dest->buf);
 		else if (!S_ISDIR(buf.st_mode))
-			die("%s exists and is not a directory\n", dest);
+			die("%s exists and is not a directory\n", dest->buf);
 	}
 
-	src_len = strlen(src);
-	src[src_len] = '/';
-	dest_len = strlen(dest);
-	dest[dest_len] = '/';
+	strbuf_addch(src, '/');
+	src_len = src->len;
+	strbuf_addch(dest, '/');
+	dest_len = dest->len;
 
 	while ((de = readdir(dir)) != NULL) {
-		strcpy(src + src_len + 1, de->d_name);
-		strcpy(dest + dest_len + 1, de->d_name);
-		if (stat(src, &buf)) {
-			warning ("failed to stat %s\n", src);
+		strbuf_setlen(src, src_len);
+		strbuf_addstr(src, de->d_name);
+		strbuf_setlen(dest, dest_len);
+		strbuf_addstr(dest, de->d_name);
+		if (stat(src->buf, &buf)) {
+			warning ("failed to stat %s\n", src->buf);
 			continue;
 		}
 		if (S_ISDIR(buf.st_mode)) {
