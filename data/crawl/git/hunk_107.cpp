 	char *line = packet_read_line(fd, &len);
 	const char *arg;
 
-	if (!len)
-		die(_("git fetch-pack: expected ACK/NAK, got EOF"));
+	if (!line)
+		die(_("git fetch-pack: expected ACK/NAK, got a flush packet"));
 	if (!strcmp(line, "NAK"))
 		return NAK;
 	if (skip_prefix(line, "ACK ", &arg)) {