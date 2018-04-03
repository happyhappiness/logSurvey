	else {
		/* Reading from stdin */
		contents_from = "standard input";
		mode = 0;
		if (strbuf_read(&buf, 0) < 0)
			die("read error %s from stdin", strerror(errno));
	}
	origin->file.ptr = buf.buf;
	origin->file.size = buf.len;
	pretend_sha1_file(buf.buf, buf.len, OBJ_BLOB, origin->blob_sha1);
	commit->util = origin;

	/*
