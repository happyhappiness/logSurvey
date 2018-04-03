 static void read_patch_file(struct strbuf *sb, int fd)
 {
 	if (strbuf_read(sb, fd, 0) < 0)
-		die("git apply: read returned %s", strerror(errno));
+		die_errno("git apply: failed to read");
 
 	/*
 	 * Make sure that we have some slop in the buffer