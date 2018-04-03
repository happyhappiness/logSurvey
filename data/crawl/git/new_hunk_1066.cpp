	}
	strbuf_addstr(&pathbuf, entry);

	if (strbuf_normalize_path(&pathbuf) < 0) {
		error("unable to normalize alternate object path: %s",
		      pathbuf.buf);
		strbuf_release(&pathbuf);
		return -1;
	}

	pfxlen = strlen(pathbuf.buf);

