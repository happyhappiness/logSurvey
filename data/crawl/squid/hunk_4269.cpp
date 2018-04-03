                              fdwAccess);		/* specify access     */
 
     if (schService == NULL) {
-        fprintf(stderr, "%s: ERROR: Could not open Service %s\n", appname,
+        fprintf(stderr, "%s: ERROR: Could not open Service %s\n", APP_SHORTNAME,
                 WIN32_Service_name);
         exit(1);
     } else {
