     check_winbindd();
 
     /* Main Loop */
-    while (fgets (buf, BUFSIZE, stdin))
+    while (fgets (buf, sizeof(buf), stdin))
     {
 	if (NULL == strchr(buf, '\n')) {
-	    err = 1;
-	    continue;
-	}
-	if (err) {
-	    warn("Oversized message\n");
+	    /* too large message received.. skip and deny */
+	    fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
+	    while (fgets(buf, sizeof(buf), stdin)) {
+		fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], buf);
+		if (strchr(buf, '\n') != NULL)
+		    break;
+	    }
 	    goto error;
 	}
 	
