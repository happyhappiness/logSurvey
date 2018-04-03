     signal(SIGHUP, Check_forchange);
 
     while (1) {
-	int n;
-	/* Read whole line from standard input. Terminate on break. */
-	memset(wstr, '\0', sizeof(wstr));
-	if (fgets(wstr, 255, stdin) == NULL)
-	    break;
-	/* ignore this line if we didn't get the end-of-line marker */
-	if (NULL == strchr(wstr, '\n')) {
-	    err = 1;
-	    continue;
-	}
-	if (err) {
-	    syslog(LOG_WARNING, "oversized message");
-	    goto error;
-	}
+        int n;
+        /* Read whole line from standard input. Terminate on break. */
+        memset(wstr, '\0', sizeof(wstr));
+        if (fgets(wstr, 255, stdin) == NULL)
+            break;
+        /* ignore this line if we didn't get the end-of-line marker */
+        if (NULL == strchr(wstr, '\n')) {
+            err = 1;
+            continue;
+        }
+        if (err) {
+            syslog(LOG_WARNING, "oversized message");
+            goto error;
+        }
 
-	/*
-	 * extract username and password.
-	 * XXX is sscanf() safe?
-	 */
-	username[0] = '\0';
-	password[0] = '\0';
-	n = sscanf(wstr, "%s %[^\n]", username, password);
-	if (2 != n) {
-	    puts("ERR");
-	    continue;
-	}
-	/* Check for invalid or blank entries */
-	if ((username[0] == '\0') || (password[0] == '\0')) {
-	    puts("ERR");
-	    continue;
-	}
-	Checktimer();		/* Check if the user lists have changed */
+        /*
+         * extract username and password.
+         * XXX is sscanf() safe?
+         */
+        username[0] = '\0';
+        password[0] = '\0';
+        n = sscanf(wstr, "%s %[^\n]", username, password);
+        if (2 != n) {
+            puts("ERR");
+            continue;
+        }
+        /* Check for invalid or blank entries */
+        if ((username[0] == '\0') || (password[0] == '\0')) {
+            puts("ERR");
+            continue;
+        }
+        Checktimer();		/* Check if the user lists have changed */
 
-	rfc1738_unescape(username);
-	rfc1738_unescape(password);
+        rfc1738_unescape(username);
+        rfc1738_unescape(password);
 
-	/*
-	 * Check if user is explicitly denied or allowed.
-	 * If user passes both checks, they can be authenticated.
-	 */
-	if (Check_user(username) == 1) {
-	    syslog(LOG_INFO, "'%s' denied", username);
-	    puts("ERR");
-	} else if (QueryServers(username, password) == 0)
-	    puts("OK");
-	else {
-	    syslog(LOG_INFO, "'%s' login failed", username);
+        /*
+         * Check if user is explicitly denied or allowed.
+         * If user passes both checks, they can be authenticated.
+         */
+        if (Check_user(username) == 1) {
+            syslog(LOG_INFO, "'%s' denied", username);
+            puts("ERR");
+        } else if (QueryServers(username, password) == 0)
+            puts("OK");
+        else {
+            syslog(LOG_INFO, "'%s' login failed", username);
 error:
-	    puts("ERR");
-	}
-	err = 0;
+            puts("ERR");
+        }
+        err = 0;
     }
 
     return 0;
