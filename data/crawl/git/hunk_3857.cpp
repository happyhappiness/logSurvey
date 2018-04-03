 	if (n >= sizeof(buffer))
 		die("protocol error: impossibly long line");
 
-	safe_write(fd, buffer, n);
+	write_or_die(fd, buffer, n);
 }
 
 static void http_status(unsigned code, const char *msg)
