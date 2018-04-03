 	free(qname);
 }
 
-static int read_old_data(struct stat *st, const char *path, char **buf_p, unsigned long *alloc_p, unsigned long *size_p)
+static int read_old_data(struct stat *st, const char *path, struct strbuf *buf)
 {
 	int fd;
-	unsigned long got;
-	struct strbuf nbuf;
-	unsigned long size = *size_p;
-	char *buf = *buf_p;
 
 	switch (st->st_mode & S_IFMT) {
 	case S_IFLNK:
-		return readlink(path, buf, size) != size;
+		strbuf_grow(buf, st->st_size);
+		if (readlink(path, buf->buf, st->st_size) != st->st_size)
+			return -1;
+		strbuf_setlen(buf, st->st_size);
+		return 0;
 	case S_IFREG:
 		fd = open(path, O_RDONLY);
 		if (fd < 0)
 			return error("unable to open %s", path);
-		got = 0;
-		for (;;) {
-			ssize_t ret = xread(fd, buf + got, size - got);
-			if (ret <= 0)
-				break;
-			got += ret;
+		if (strbuf_read(buf, fd, st->st_size) < 0) {
+			close(fd);
+			return -1;
 		}
 		close(fd);
-		strbuf_init(&nbuf, 0);
-		if (convert_to_git(path, buf, size, &nbuf)) {
-			free(buf);
-			*buf_p = nbuf.buf;
-			*alloc_p = nbuf.alloc;
-			*size_p = nbuf.len;
-		}
-		return got != size;
+		convert_to_git(path, buf->buf, buf->len, buf);
+		return 0;
 	default:
 		return -1;
 	}
