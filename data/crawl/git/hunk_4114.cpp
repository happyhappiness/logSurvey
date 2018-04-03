 	return newpath;
 }
 
-static void flush_buffer(int fd, const char *buf, unsigned long size)
-{
-	while (size > 0) {
-		long ret = write_in_full(fd, buf, size);
-		if (ret < 0) {
-			/* Ignore epipe */
-			if (errno == EPIPE)
-				break;
-			die_errno("merge-recursive");
-		} else if (!ret) {
-			die(_("merge-recursive: disk full?"));
-		}
-		size -= ret;
-		buf += ret;
-	}
-}
-
 static int dir_in_way(const char *path, int check_working_copy)
 {
 	int pos, pathlen = strlen(path);
