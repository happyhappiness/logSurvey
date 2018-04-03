     }
     if ((conn = client_comm_connect(conn, hostname, portnum)) < 0) {
 	printf("Error: connecting to cache mgr: %s:%d\n", hostname, portnum);
-	printf("%s</PRE>\n", xstrerror());
+	printf("%s</PRE></BODY></HTML>\n", xstrerror());
 	exit(1);
     }
     bytesWritten = write(conn, msg, strlen(msg));
