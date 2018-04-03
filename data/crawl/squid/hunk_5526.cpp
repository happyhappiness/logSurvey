 	if (bytesWritten < 0) {
 	    perror("client: ERROR: write");
 	    exit(1);
-	} else if (bytesWritten != strlen(msg)) {
+	} else if ((unsigned) bytesWritten != strlen(msg)) {
 	    fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
 	    exit(1);
 	}
