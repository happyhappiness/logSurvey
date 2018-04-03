   current_entry = load_dict (FH);
 
   while (fgets (line, sizeof (line), stdin)) {
-    if ((cp = strchr (line, '\n')) != NULL) {
-      *cp = '\0';
+    if ((cp = strchr (line, '\n')) == NULL) {
+	/* too large message received.. skip and deny */
+	fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], line);
+	while (fgets(line, sizeof(line), stdin)) {
+	    fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], line);
+	    if (strchr(line, '\n') != NULL)
+		break;
+	}
+	goto error;
     }
-    if ((cp = strtok (line, " \t")) != NULL) {
-      address = cp;
-      username = strtok (NULL, " \t");
-    } else {
-      fprintf (stderr, "helper: unable to read tokens\n");
-      printf ("ERR\n");
-      continue;
+    *cp = '\0';
+    address = strtok (line, " \t");
+    username = strtok (NULL, " \t");
+    if (!address || !username) {
+      fprintf (stderr, "%s: unable to read tokens\n", argv[0]);
+      goto error;
     }
+    rfc1738_unescape(address);
+    rfc1738_unescape(username);
 #ifdef DEBUG
     printf ("result: %d\n",
 	    dict_lookup (current_entry, username, address));
 #endif
     if ((dict_lookup (current_entry, username, address)) != 0) {
       printf ("OK\n");
     } else {
+error:
       printf ("ERR\n");
     }
-
-
   }
 
 
