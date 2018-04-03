         /* LDAP can't bind with a blank password. Seen as "anonymous"
          * and always granted access
          */
-        if (debug_mode)
-            fprintf(stderr, "Blank password given\n");
+        debug("Blank password given\n");
         return 1;
     }
     if (searchfilter) {
