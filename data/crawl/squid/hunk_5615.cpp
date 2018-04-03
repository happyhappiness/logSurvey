     /* Main Loop */
     while (fgets (buf, BUFSIZE, stdin))
     {
-	
+	if (NULL == strchr(buf, '\n')) {
+	    err = 1;
+	    continue;
+	}
+	if (err) {
+	    warn("Oversized message\n");
+	    goto error;
+	}
+
 	if ((p = strchr(buf, '\n')) != NULL)
 	    *p = '\0';		/* strip \n */
 	if ((p = strchr(buf, '\r')) != NULL)
 	    *p = '\0';		/* strip \r */
 
 	debug("Got '%s' from Squid (length: %d).\n",buf,sizeof(buf));
-	
+
+	if (buf[0] == '\0') {
+	    warn("Invalid Request\n");
+	    goto error;
+	}
+
 	username = strwordtok(buf, &t);
 	group = strwordtok(NULL, &t);
 
 	if (Valid_Group(username, group)) {
 	    printf ("OK\n");
 	} else {
+error:
 	    printf ("ERR\n");
 	}
+	err = 0;
     }
     return 0;
 }
