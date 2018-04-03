 
 	len = packet_read_line(fd[0], buf, sizeof(buf));
 	if (!len)
-		die("git-archive: expected ACK/NAK, got EOF");
+		die("git archive: expected ACK/NAK, got EOF");
 	if (buf[len-1] == '\n')
 		buf[--len] = 0;
 	if (strcmp(buf, "ACK")) {
 		if (len > 5 && !prefixcmp(buf, "NACK "))
-			die("git-archive: NACK %s", buf + 5);
-		die("git-archive: protocol error");
+			die("git archive: NACK %s", buf + 5);
+		die("git archive: protocol error");
 	}
 
 	len = packet_read_line(fd[0], buf, sizeof(buf));
 	if (len)
-		die("git-archive: expected a flush");
+		die("git archive: expected a flush");
 
 	/* Now, start reading from fd[0] and spit it out to stdout */
 	rv = recv_sideband("archive", fd[0], 1, 2);
