	strbuf_release(&nbuf);

	if (close(fd) < 0)
		die_errno("closing file '%s'", path);
	return 0;
}

