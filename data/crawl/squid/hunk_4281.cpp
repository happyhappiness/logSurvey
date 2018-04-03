     int i;
 
     if (f == NULL || !strcmp(Config.pidFilename, "none")) {
-        fprintf(stderr, "%s: ERROR: No pid file name defined\n", appname);
+        fprintf(stderr, APP_SHORTNAME ": ERROR: No pid file name defined\n");
         exit(1);
     }
 
