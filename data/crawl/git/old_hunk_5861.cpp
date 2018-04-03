		contents_from = "standard input";
		mode = 0;
		if (strbuf_read(&buf, 0, 0) < 0)
			die("read error %s from stdin", strerror(errno));
	}
	convert_to_git(path, buf.buf, buf.len, &buf, 0);
	origin->file.ptr = buf.buf;
