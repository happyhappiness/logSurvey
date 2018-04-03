     debug((char *) "%s| %s: DEBUG: Found %d ldap entr%s\n", LogTime(), PROGRAM, ldap_count_entries(ld, res), ldap_count_entries(ld, res) > 1 || ldap_count_entries(ld, res) == 0 ? "ies" : "y");
 
     if (ldap_count_entries(ld, res) != 0) {
+        size_t k;
 
         if (margs->AD)
-            max_attr = get_attributes(margs, ld, res, ATTRIBUTE_AD, &attr_value);
+            max_attr = get_attributes(ld, res, ATTRIBUTE_AD, &attr_value);
         else {
-            max_attr = get_attributes(margs, ld, res, ATTRIBUTE, &attr_value);
+            max_attr = get_attributes(ld, res, ATTRIBUTE, &attr_value);
         }
 
         /*
          * Compare group names
          */
         retval = 0;
-        for (j = 0; j < max_attr; ++j) {
+        for (k = 0; k < max_attr; ++k) {
+            char *av = NULL;
 
             /* Compare first CN= value assuming it is the same as the group name itself */
-            av = attr_value[j];
+            av = attr_value[k];
             if (!strncasecmp("CN=", av, 3)) {
+                char *avp = NULL;
                 av += 3;
                 if ((avp = strchr(av, ','))) {
                     *avp = '\0';
                 }
             }
             if (debug_enabled) {
                 int n;
-                debug((char *) "%s| %s: DEBUG: Entry %d \"%s\" in hex UTF-8 is ", LogTime(), PROGRAM, j + 1, av);
+                debug((char *) "%s| %s: DEBUG: Entry %ld \"%s\" in hex UTF-8 is ", LogTime(), PROGRAM, k + 1, av);
                 for (n = 0; av[n] != '\0'; ++n)
                     fprintf(stderr, "%02x", (unsigned char) av[n]);
                 fprintf(stderr, "\n");
             }
             if (!strcasecmp(group, av)) {
                 retval = 1;
                 if (debug_enabled)
-                    debug((char *) "%s| %s: DEBUG: Entry %d \"%s\" matches group name \"%s\"\n", LogTime(), PROGRAM, j + 1, av, group);
+                    debug((char *) "%s| %s: DEBUG: Entry %ld \"%s\" matches group name \"%s\"\n", LogTime(), PROGRAM, k + 1, av, group);
                 else
                     break;
             } else
-                debug((char *) "%s| %s: DEBUG: Entry %d \"%s\" does not match group name \"%s\"\n", LogTime(), PROGRAM, j + 1, av, group);
+                debug((char *) "%s| %s: DEBUG: Entry %ld \"%s\" does not match group name \"%s\"\n", LogTime(), PROGRAM, k + 1, av, group);
         }
         /*
          * Do recursive group search for AD only since posixgroups can not contain other groups
          */
         if (!retval && margs->AD) {
+            size_t j;
             if (debug_enabled && max_attr > 0) {
                 debug((char *) "%s| %s: DEBUG: Perform recursive group search\n", LogTime(), PROGRAM);
             }
             for (j = 0; j < max_attr; ++j) {
+                char *av = NULL;
 
                 av = attr_value[j];
                 if (search_group_tree(margs, ld, bindp, av, group, 1)) {
                     retval = 1;
                     if (!strncasecmp("CN=", av, 3)) {
+                        char *avp = NULL;
                         av += 3;
                         if ((avp = strchr(av, ','))) {
                             *avp = '\0';
                         }
                     }
                     if (debug_enabled)
-                        debug((char *) "%s| %s: DEBUG: Entry %d group \"%s\" is (in)direct member of group \"%s\"\n", LogTime(), PROGRAM, j + 1, av, group);
+                        debug((char *) "%s| %s: DEBUG: Entry %ld group \"%s\" is (in)direct member of group \"%s\"\n", LogTime(), PROGRAM, j + 1, av, group);
                     else
                         break;
                 }
