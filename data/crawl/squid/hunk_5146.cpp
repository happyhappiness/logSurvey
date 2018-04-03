 	exit(1);
     }
     while (fgets(buf, 256, stdin) != NULL) {
-	char *tptr;
 	int found = 0;
-	user = strwordtok(buf, &tptr);
-	if (user && strip_nt_domain) {
+	if (!strchr(buf, '\n')) {
+	    /* too large message received.. skip and deny */
+	    fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
+	    while (fgets(buf, sizeof(buf), stdin)) {
+		fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], buf);
+		if (strchr(buf, '\n') != NULL)
+		    break;
+	    }
+	    goto error;
+	}
+	user = strtok(buf, " \n");
+	if (!user) {
+	    fprintf(stderr, "%s: Invalid request\n", argv[0]);
+	    goto error;
+	}
+	rfc1738_unescape(user);
+	if (strip_nt_domain) {
 	    char *u = strchr(user, '\\');
 	    if (!u)
 		u = strchr(user, '/');
 	    if (u && u[1])
 		user = u + 1;
 	}
-	if (use_extension_dn)
-		extension_dn = strwordtok(NULL, &tptr);
+	if (use_extension_dn) {
+	    extension_dn = strtok(NULL, " \n");
+	    if (!extension_dn) {
+		fprintf(stderr, "%s: Invalid request\n", argv[0]);
+		goto error;
+	    }
+	    rfc1738_unescape(extension_dn);
+	}
 
-	while (!found && user && (group = strwordtok(NULL, &tptr)) != NULL) {
+	while (!found && user && (group = strtok(NULL, " \n")) != NULL) {
+	    rfc1738_unescape(group);
 
 	  recover:
 	    if (ld == NULL) {
