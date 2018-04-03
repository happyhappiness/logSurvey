	strbuf_release(&nbuf);

	if (close(fd) < 0)
		die("closing file %s: %s", path, strerror(errno));
	return 0;
}

