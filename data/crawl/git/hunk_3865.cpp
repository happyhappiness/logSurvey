 		len = packet_read_line(in, line, sizeof(line));
 		if (!len)
 			break;
-		if (len < 3 ||
-		    (memcmp(line, "ok ", 3) && memcmp(line, "ng ", 3))) {
-			fprintf(stderr, "protocol error: %s\n", line);
+		if (prefixcmp(line, "ok ") && prefixcmp(line, "ng ")) {
+			error("invalid ref status from remote: %s", line);
 			ret = -1;
 			break;
 		}