	}
	strbuf_addstr(&pathbuf, entry);

	normalize_path_copy(pathbuf.buf, pathbuf.buf);

	pfxlen = strlen(pathbuf.buf);

