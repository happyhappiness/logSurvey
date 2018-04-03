 		if (lstat(name, &st) < 0) {
 			if (errno == ENOENT)
 				goto not_a_valid_file;
-			die("stat(%s): %s", name, strerror(errno));
+			die_errno("stat(%s)", name);
 		}
 		if (S_ISLNK(st.st_mode)) {
 			struct strbuf sb = STRBUF_INIT;
