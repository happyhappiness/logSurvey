	strbuf_release(&out);
}

ssize_t safe_write(int fd, const void *buf, ssize_t n)
{
	ssize_t nn = n;
	while (n) {
		int ret = xwrite(fd, buf, n);
		if (ret > 0) {
			buf = (char *) buf + ret;
			n -= ret;
			continue;
		}
		if (!ret)
			die("write error (disk full?)");
		die_errno("write error");
	}
	return nn;
}

/*
 * If we buffered things up above (we don't, but we should),
 * we'd flush it here
 */
void packet_flush(int fd)
{
	packet_trace("0000", 4, 1);
	safe_write(fd, "0000", 4);
}

void packet_buf_flush(struct strbuf *buf)
