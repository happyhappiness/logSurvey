     struct addrinfo *hres = NULL, *hres_list;
     int rc, count;
 
-    rc = gethostname(hostname, sysconf(_SC_HOST_NAME_MAX));
+    rc = gethostname(hostname, sizeof(hostname)-1);
     if (rc) {
         fprintf(stderr, "%s| %s: ERROR: resolving hostname '%s' failed\n",
                 LogTime(), PROGRAM, hostname);
