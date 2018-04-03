 	die("git fetch_pack: expected ACK/NAK, got '%s'", line);
 }
 
+static void send_request(int fd, struct strbuf *buf)
+{
+	if (args.stateless_rpc) {
+		send_sideband(fd, -1, buf->buf, buf->len, LARGE_PACKET_MAX);
+		packet_flush(fd);
+	} else
+		safe_write(fd, buf->buf, buf->len);
+}
+
 static int find_common(int fd[2], unsigned char *result_sha1,
 		       struct ref *refs)
 {
