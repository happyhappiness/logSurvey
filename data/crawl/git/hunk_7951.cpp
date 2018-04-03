 		mode = canon_mode(st.st_mode);
 		switch (st.st_mode & S_IFMT) {
 		case S_IFREG:
-			fd = open(read_from, O_RDONLY);
-			if (fd < 0)
-				die("cannot open %s", read_from);
-			if (strbuf_read(&buf, fd, 0) != xsize_t(st.st_size))
-				die("cannot read %s", read_from);
+			if (strbuf_read_file(&buf, read_from, st.st_size) != st.st_size)
+				die("cannot open or read %s", read_from);
 			break;
 		case S_IFLNK:
 			if (readlink(read_from, buf.buf, buf.alloc) != fin_size)
