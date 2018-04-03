		strbuf_setlen(buf, st->st_size);
		return 0;
	case S_IFREG:
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return error("unable to open %s", path);
		if (strbuf_read(buf, fd, st->st_size) < 0) {
			close(fd);
			return -1;
		}
		close(fd);
		convert_to_git(path, buf->buf, buf->len, buf);
		return 0;
	default:
