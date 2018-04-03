 void packet_buf_write(struct strbuf *buf, const char *fmt, ...) __attribute__((format (printf, 2, 3)));
 
 /*
- * Read a packetized line from the descriptor into the buffer, which must be at
- * least size bytes long. The return value specifies the number of bytes read
- * into the buffer.
+ * Read a packetized line into the buffer, which must be at least size bytes
+ * long. The return value specifies the number of bytes read into the buffer.
+ *
+ * If src_buffer is not NULL (and nor is *src_buffer), it should point to a
+ * buffer containing the packet data to parse, of at least *src_len bytes.
+ * After the function returns, src_buf will be incremented and src_len
+ * decremented by the number of bytes consumed.
+ *
+ * If src_buffer (or *src_buffer) is NULL, then data is read from the
+ * descriptor "fd".
  *
  * If options does not contain PACKET_READ_GENTLE_ON_EOF, we will die under any
  * of the following conditions:
