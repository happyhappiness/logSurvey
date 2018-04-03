		else
			ret = -1;
		strbuf_release(&sbuf);
	} else if (size <= SMALL_FILE_SIZE) {
		char *buf = xmalloc(size);
		if (size == read_in_full(fd, buf, size))
			ret = index_mem(sha1, buf, size, write_object, type,
					path);
		else
			ret = error("short read %s", strerror(errno));
		free(buf);
	} else if (size) {
		void *buf = xmmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
		ret = index_mem(sha1, buf, size, write_object, type, path);