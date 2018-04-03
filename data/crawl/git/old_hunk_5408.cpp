		else
			ret = -1;
		strbuf_release(&sbuf);
	} else if (size) {
		void *buf = xmmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
		ret = index_mem(sha1, buf, size, write_object, type, path);