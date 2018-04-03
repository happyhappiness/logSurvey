 	return count;
 }
 
+static ssize_t strbuf_read_file_or_whine(struct strbuf *sb, const char *path)
+{
+	int fd;
+	ssize_t len;
+
+	fd = open(path, O_RDONLY);
+	if (fd < 0)
+		return error_errno(_("could not open '%s'"), path);
+	len = strbuf_read(sb, fd, 0);
+	close(fd);
+	if (len < 0)
+		return error(_("could not read '%s'."), path);
+	return len;
+}
+
 static int read_populate_todo(struct todo_list *todo_list,
 			struct replay_opts *opts)
 {
 	struct stat st;
 	const char *todo_file = get_todo_path(opts);
-	int fd, res;
+	int res;
 
 	strbuf_reset(&todo_list->buf);
-	fd = open(todo_file, O_RDONLY);
-	if (fd < 0)
-		return error_errno(_("could not open '%s'"), todo_file);
-	if (strbuf_read(&todo_list->buf, fd, 0) < 0) {
-		close(fd);
-		return error(_("could not read '%s'."), todo_file);
-	}
-	close(fd);
+	if (strbuf_read_file_or_whine(&todo_list->buf, todo_file) < 0)
+		return -1;
 
 	res = stat(todo_file, &st);
 	if (res)
