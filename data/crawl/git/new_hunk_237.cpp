int packet_flush_gently(int fd)
{
	packet_trace("0000", 4, 1);
	if (write_in_full(fd, "0000", 4) < 0)
		return error("flush packet write failed");
	return 0;
}

void packet_buf_flush(struct strbuf *buf)
