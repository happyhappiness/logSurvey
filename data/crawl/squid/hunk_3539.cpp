 
     rc = gethostname(hostname, sysconf(_SC_HOST_NAME_MAX));
     if (rc) {
-	fprintf(stderr, "%s| %s: error while resolving hostname '%s'\n",
-	    LogTime(), PROGRAM, hostname);
-	return NULL;
+        fprintf(stderr, "%s| %s: error while resolving hostname '%s'\n",
+                LogTime(), PROGRAM, hostname);
+        return NULL;
     }
     rc = xgetaddrinfo(hostname, NULL, NULL, &hres);
     if (rc != 0) {
-	fprintf(stderr,
-	    "%s| %s: error while resolving hostname with getaddrinfo: %s\n",
-	    LogTime(), PROGRAM, xgai_strerror(rc));
-	return NULL;
+        fprintf(stderr,
+                "%s| %s: error while resolving hostname with getaddrinfo: %s\n",
+                LogTime(), PROGRAM, xgai_strerror(rc));
+        return NULL;
     }
     hres_list = hres;
     count = 0;
     while (hres_list) {
-	count++;
-	hres_list = hres_list->ai_next;
+        count++;
+        hres_list = hres_list->ai_next;
     }
     rc = xgetnameinfo(hres->ai_addr, hres->ai_addrlen, hostname,
-	sizeof(hostname), NULL, 0, 0);
+                      sizeof(hostname), NULL, 0, 0);
     if (rc != 0) {
-	fprintf(stderr,
-	    "%s| %s: error while resolving ip address with getnameinfo: %s\n",
-	    LogTime(), PROGRAM, xgai_strerror(rc));
-	xfreeaddrinfo(hres);
-	return NULL;
+        fprintf(stderr,
+                "%s| %s: error while resolving ip address with getnameinfo: %s\n",
+                LogTime(), PROGRAM, xgai_strerror(rc));
+        xfreeaddrinfo(hres);
+        return NULL;
     }
 
     xfreeaddrinfo(hres);