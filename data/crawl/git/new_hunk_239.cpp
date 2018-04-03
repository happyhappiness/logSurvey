	packet_size = size + 4;
	set_packet_header(packet_write_buffer, packet_size);
	memcpy(packet_write_buffer + 4, buf, size);
	if (write_in_full(fd_out, packet_write_buffer, packet_size) < 0)
		return error("packet write failed");
	return 0;
}

void packet_buf_write(struct strbuf *buf, const char *fmt, ...)