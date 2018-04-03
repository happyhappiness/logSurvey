 	if (args.depth > 0) {
 		char line[1024];
 		unsigned char sha1[20];
-		int len;
 
-		while ((len = packet_read_line(fd[0], line, sizeof(line)))) {
+		while (packet_read_line(fd[0], line, sizeof(line))) {
 			if (!prefixcmp(line, "shallow ")) {
 				if (get_sha1_hex(line + 8, sha1))
 					die("invalid shallow line: %s", line);
