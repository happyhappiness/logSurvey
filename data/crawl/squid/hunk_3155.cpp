         snprintf(searchbase, sizeof(searchbase), "%s", basedn);
 
     if (build_filter(filter, sizeof(filter), searchfilter, member, group) != 0) {
-        fprintf(stderr, PROGRAM_NAME " ERROR, Failed to construct LDAP search filter. filter=\"%s\", user=\"%s\", group=\"%s\"\n", filter, member, group);
+        fprintf(stderr, PROGRAM_NAME ": ERROR: Failed to construct LDAP search filter. filter=\"%s\", user=\"%s\", group=\"%s\"\n", filter, member, group);
         return 1;
     }
-    if (show_debug_messages)
-        fprintf(stderr, "group filter '%s', searchbase '%s'\n", filter, searchbase);
+    debug("group filter '%s', searchbase '%s'\n", filter, searchbase);
 
     rc = ldap_search_s(ld, searchbase, searchscope, filter, searchattr, 1, &res);
     if (rc != LDAP_SUCCESS) {
