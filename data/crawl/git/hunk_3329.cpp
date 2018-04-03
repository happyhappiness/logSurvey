 	free(buf);
 }
 
-static void remove_subtree(const char *path)
+static void remove_subtree(struct strbuf *path)
 {
-	DIR *dir = opendir(path);
+	DIR *dir = opendir(path->buf);
 	struct dirent *de;
-	char pathbuf[PATH_MAX];
-	char *name;
+	int origlen = path->len;
 
 	if (!dir)
-		die_errno("cannot opendir '%s'", path);
-	strcpy(pathbuf, path);
-	name = pathbuf + strlen(path);
-	*name++ = '/';
+		die_errno("cannot opendir '%s'", path->buf);
 	while ((de = readdir(dir)) != NULL) {
 		struct stat st;
+
 		if (is_dot_or_dotdot(de->d_name))
 			continue;
-		strcpy(name, de->d_name);
-		if (lstat(pathbuf, &st))
-			die_errno("cannot lstat '%s'", pathbuf);
+
+		strbuf_addch(path, '/');
+		strbuf_addstr(path, de->d_name);
+		if (lstat(path->buf, &st))
+			die_errno("cannot lstat '%s'", path->buf);
 		if (S_ISDIR(st.st_mode))
-			remove_subtree(pathbuf);
-		else if (unlink(pathbuf))
-			die_errno("cannot unlink '%s'", pathbuf);
+			remove_subtree(path);
+		else if (unlink(path->buf))
+			die_errno("cannot unlink '%s'", path->buf);
+		strbuf_setlen(path, origlen);
 	}
 	closedir(dir);
-	if (rmdir(path))
-		die_errno("cannot rmdir '%s'", path);
+	if (rmdir(path->buf))
+		die_errno("cannot rmdir '%s'", path->buf);
 }
 
 static int create_file(const char *path, unsigned int mode)
