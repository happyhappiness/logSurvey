	}
	if (close(fd) < 0)
		die("closing file %s: %s", path, strerror(errno));
	strbuf_release(&nbuf);
	return 0;
}

