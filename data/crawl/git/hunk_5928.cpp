 		return NULL;
 	fd = open(path, O_RDONLY);
 	if (fd < 0)
-		die("Error opening %s: %s", path, strerror(errno));
+		die_errno("Error opening '%s'", path);
 	buf = xmalloc(st.st_size + 1);
 	len = read_in_full(fd, buf, st.st_size);
 	close(fd);
