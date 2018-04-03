             snprintf(searchbase, 8192, "%s=%s, %s", userdnattr, login, userbasedn);
 
 retrydnattr:
-            if (show_debug_messages)
-                fprintf(stderr, "searchbase '%s'\n", searchbase);
+            debug("searchbase '%s'\n", searchbase);
             rc = ldap_search_s(ld, searchbase, searchscope, NULL, NULL, 0, &res);
         }
         if (rc == LDAP_SUCCESS) {
