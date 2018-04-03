 
 static void safe_read(int fd, void *buffer, unsigned size)
 {
-	size_t n = 0;
-
-	while (n < size) {
-		ssize_t ret = xread(fd, (char *) buffer + n, size - n);
-		if (ret < 0)
-			die("read error (%s)", strerror(errno));
-		if (!ret)
-			die("The remote end hung up unexpectedly");
-		n += ret;
-	}
+	ssize_t ret = read_in_full(fd, buffer, size);
+	if (ret < 0)
+		die("read error (%s)", strerror(errno));
+	else if (ret < size)
+		die("The remote end hung up unexpectedly");
 }
 
 int packet_read_line(int fd, char *buffer, unsigned size)
