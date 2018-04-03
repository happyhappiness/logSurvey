void packet_buf_write(struct strbuf *buf, const char *fmt, ...) __attribute__((format (printf, 2, 3)));

/*
 * Read a packetized line from the descriptor into the buffer, which must be at
 * least size bytes long. The return value specifies the number of bytes read
 * into the buffer.
 *
 * If options does not contain PACKET_READ_GENTLE_ON_EOF, we will die under any
 * of the following conditions:
