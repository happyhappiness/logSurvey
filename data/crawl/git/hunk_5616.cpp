 			len += c - 'A' + 10;
 			continue;
 		}
-		die("protocol error: bad line length character");
+		return -1;
 	}
+	return len;
+}
+
+int packet_read_line(int fd, char *buffer, unsigned size)
+{
+	int len;
+	char linelen[4];
+
+	safe_read(fd, linelen, 4);
+	len = packet_length(linelen);
+	if (len < 0)
+		die("protocol error: bad line length character");
 	if (!len)
 		return 0;
 	len -= 4;
