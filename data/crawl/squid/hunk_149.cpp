         }
         if (debug_enabled) {
             int n;
-            debug((char *) "%s| %s: DEBUG: Entry %" PRIuSIZE " \"%s\" in hex UTF-8 is ", LogTime(), PROGRAM, j + 1, av);
+            debug((char *) "%s| %s: DEBUG: Entry %" PRIuSIZE
+                  " \"%s\" in hex UTF-8 is ", LogTime(), PROGRAM, j + 1, av);
             for (n = 0; av[n] != '\0'; ++n)
                 fprintf(stderr, "%02x", (unsigned char) av[n]);
             fprintf(stderr, "\n");
         }
         if (!strcasecmp(group, av)) {
             retval = 1;
-            debug((char *) "%s| %s: DEBUG: Entry %" PRIuSIZE " \"%s\" matches group name \"%s\"\n", LogTime(), PROGRAM, j + 1, av, group);
+            debug((char *) "%s| %s: DEBUG: Entry %" PRIuSIZE
+                  " \"%s\" matches group name \"%s\"\n", LogTime(), PROGRAM,
+                  j + 1, av, group);
             break;
         } else
-            debug((char *) "%s| %s: DEBUG: Entry %" PRIuSIZE " \"%s\" does not match group name \"%s\"\n", LogTime(), PROGRAM, j + 1, av, group);
+            debug((char *) "%s| %s: DEBUG: Entry %" PRIuSIZE
+                  " \"%s\" does not match group name \"%s\"\n", LogTime(),
+                  PROGRAM, j + 1, av, group);
         /*
          * Do recursive group search
          */
-        debug((char *) "%s| %s: DEBUG: Perform recursive group search for group \"%s\"\n", LogTime(), PROGRAM, av);
+        debug((char *)
+              "%s| %s: DEBUG: Perform recursive group search for group \"%s\"\n",
+              LogTime(), PROGRAM, av);
         av = attr_value[j];
         if (search_group_tree(margs, ld, bindp, av, group, ldepth)) {
             retval = 1;
