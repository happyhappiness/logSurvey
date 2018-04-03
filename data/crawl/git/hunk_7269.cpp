 	return 0;
 }
 
+/*
+ * Try to read the location of the git directory from the .git file,
+ * return path to git directory if found.
+ */
+const char *read_gitfile_gently(const char *path)
+{
+	char *buf;
+	struct stat st;
+	int fd;
+	size_t len;
+
+	if (stat(path, &st))
+		return NULL;
+	if (!S_ISREG(st.st_mode))
+		return NULL;
+	fd = open(path, O_RDONLY);
+	if (fd < 0)
+		die("Error opening %s: %s", path, strerror(errno));
+	buf = xmalloc(st.st_size + 1);
+	len = read_in_full(fd, buf, st.st_size);
+	close(fd);
+	if (len != st.st_size)
+		die("Error reading %s", path);
+	buf[len] = '\0';
+	if (prefixcmp(buf, "gitdir: "))
+		die("Invalid gitfile format: %s", path);
+	while (buf[len - 1] == '\n' || buf[len - 1] == '\r')
+		len--;
+	if (len < 9)
+		die("No path in gitfile: %s", path);
+	buf[len] = '\0';
+	if (!is_git_directory(buf + 8))
+		die("Not a git repository: %s", buf + 8);
+	path = make_absolute_path(buf + 8);
+	free(buf);
+	return path;
+}
+
 /*
  * We cannot decide in this function whether we are in the work tree or
  * not, since the config can only be read _after_ this function was called.
