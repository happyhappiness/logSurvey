     char *ch2, *decoded, *cred;
     int plen;
 
-    if (fgets(buf, BUFFER_SIZE, stdin) == NULL)
-	exit(0);		/* BIIG buffer */
+    if (fgets(buf, BUFFER_SIZE, stdin) == NULL) {
+	fprintf(stderr, "fgets() failed! dying..... errno=%d (%s)\n", errno,
+	    strerror(errno));
+	abort();
+	exit(1);		/* BIIG buffer */
+    }
+    debug("managing request\n");
     ch2 = memchr(buf, '\n', BUFFER_SIZE);	/* safer against overrun than strchr */
     if (ch2) {
 	*ch2 = '\0';		/* terminate the string at newline. */
