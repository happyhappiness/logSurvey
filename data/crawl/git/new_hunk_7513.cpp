		if (strbuf_read(&buf, 0, 0) < 0)
			die("read error %s from stdin", strerror(errno));
	}
	convert_to_git(path, buf.buf, buf.len, &buf, 0);
	origin->file.ptr = buf.buf;
	origin->file.size = buf.len;
	pretend_sha1_file(buf.buf, buf.len, OBJ_BLOB, origin->blob_sha1);
