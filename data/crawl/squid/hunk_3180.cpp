     struct group *g;
 
     if ((g = getgrnam(groupname)) == NULL) {
-        fprintf(stderr, "helper: Group does not exist '%s'\n",
-                groupname);
+        fprintf(stderr, "ERROR: Group does not exist '%s'\n", groupname);
         return 0;
     } else {
         while (*(g->gr_mem) != NULL) {
