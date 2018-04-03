 	static char tmpfile[PATH_MAX];
 
 	filename = sha1_file_name(sha1);
-	fd = open(filename, O_RDONLY);
-	if (fd >= 0) {
-		/*
-		 * FIXME!!! We might do collision checking here, but we'd
-		 * need to uncompress the old file and check it. Later.
-		 */
-		close(fd);
-		return 0;
-	}
-
-	if (errno != ENOENT) {
-		return error("sha1 file %s: %s\n", filename, strerror(errno));
-	}
-
 	fd = create_tmpfile(tmpfile, sizeof(tmpfile), filename);
 	if (fd < 0) {
 		if (errno == EPERM)