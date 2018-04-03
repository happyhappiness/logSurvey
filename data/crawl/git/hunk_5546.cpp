 	ACK_ready
 };
 
+static void consume_shallow_list(int fd)
+{
+	if (args.stateless_rpc && args.depth > 0) {
+		/* If we sent a depth we will get back "duplicate"
+		 * shallow and unshallow commands every time there
+		 * is a block of have lines exchanged.
+		 */
+		char line[1000];
+		while (packet_read_line(fd, line, sizeof(line))) {
+			if (!prefixcmp(line, "shallow "))
+				continue;
+			if (!prefixcmp(line, "unshallow "))
+				continue;
+			die("git fetch-pack: expected shallow list");
+		}
+	}
+}
+
 static enum ack_type get_ack(int fd, unsigned char *result_sha1)
 {
 	static char line[1000];
