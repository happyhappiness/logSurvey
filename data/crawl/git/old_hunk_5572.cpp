			break;
		if (!prefixcmp(buf.buf, "fetch ")) {
			char *obj = buf.buf + strlen("fetch ");
			if (!walker)
				walker = get_http_walker(url, remote);
			walker->get_all = 1;