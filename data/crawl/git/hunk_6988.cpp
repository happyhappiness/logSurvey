 		mode = 0100666;
 		sprintf(header.name, "%s.paxheader", sha1_to_hex(sha1));
 	} else {
-		if (verbose)
-			fprintf(stderr, "%.*s\n", (int)path->len, path->buf);
 		if (S_ISDIR(mode) || S_ISGITLINK(mode)) {
 			*header.typeflag = TYPEFLAG_DIR;
 			mode = (mode | 0777) & ~tar_umask;
