		mode = canon_mode(st.st_mode);
		switch (st.st_mode & S_IFMT) {
		case S_IFREG:
			if (strbuf_read_file(&buf, read_from, st.st_size) != st.st_size)
				die("cannot open or read %s", read_from);
			break;
		case S_IFLNK:
			if (readlink(read_from, buf.buf, buf.alloc) != fin_size)
