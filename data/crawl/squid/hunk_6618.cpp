 	    int x;
 	    while ((x = read(put_fd, msg, BUFSIZ)) > 0) {
 		x = write(conn, msg, x);
+		total_bytes+=x;
 		if (x <= 0)
 		    break;
 	    }
-	    if (x != 0) {
+	    if (x != 0) 
 		fprintf(stderr, "client: ERROR: Cannot send file.\n");
-		exit(1);
-	    }
+	    fprintf(stderr, "TOTAL SENT: %d\n",total_bytes);
 	    close(put_fd);
 	}
 	/* Read the data */
+
 	while ((len = read(conn, buf, sizeof(buf))) > 0) {
 	    if (to_stdout)
 		fwrite(buf, len, 1, stdout);
