 			read_from = path;
 		}
 		fin_size = xsize_t(st.st_size);
-		buf = xmalloc(fin_size+1);
 		mode = canon_mode(st.st_mode);
 		switch (st.st_mode & S_IFMT) {
 		case S_IFREG:
 			fd = open(read_from, O_RDONLY);
 			if (fd < 0)
 				die("cannot open %s", read_from);
-			if (read_in_full(fd, buf, fin_size) != fin_size)
+			if (strbuf_read(&buf, fd) != xsize_t(st.st_size))
 				die("cannot read %s", read_from);
 			break;
 		case S_IFLNK:
-			if (readlink(read_from, buf, fin_size+1) != fin_size)
+			if (readlink(read_from, buf.buf, buf.alloc) != fin_size)
 				die("cannot readlink %s", read_from);
+			buf.len = fin_size;
 			break;
 		default:
 			die("unsupported file type %s", read_from);
