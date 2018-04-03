             snprintf(searchbase, 8192, "%s=%s, %s", userdnattr, login, userbasedn);
 
 retrydnattr:
-            if (show_debug_messages)
-                fprintf(stderr, "searchbase '%s'\n", searchbase);
+            debug("searchbase '%s'\n", searchbase);
             rc = ldap_search_s(ld, searchbase, searchscope, NULL, NULL, 0, &res);
         }
         if (rc == LDAP_SUCCESS) {
             entry = ldap_first_entry(ld, res);
             if (entry) {
-                if (show_debug_messages)
-                    printf("ldap dn: %s\n", ldap_get_dn(ld, entry));
+                debug("ldap dn: %s\n", ldap_get_dn(ld, entry));
                 if (edir_universal_passwd) {
 
                     /* allocate some memory for the universal password returned by NMAS */
-                    universal_password = malloc(universal_password_len);
-                    memset(universal_password, 0, universal_password_len);
-                    values = malloc(sizeof(char *));
+                    universal_password = (char*)calloc(1, universal_password_len);
+                    values = (char**)calloc(1, sizeof(char *));
 
                     /* actually talk to NMAS to get a password */
                     nmas_res = nds_get_password(ld, ldap_get_dn(ld, entry), &universal_password_len, universal_password);
                     if (nmas_res == LDAP_SUCCESS && universal_password) {
-                        if (show_debug_messages)
-                            printf("NMAS returned value %s\n", universal_password);
+                        debug("NMAS returned value %s\n", universal_password);
                         values[0] = universal_password;
                     } else {
-                        if (show_debug_messages)
-                            printf("Error reading Universal Password: %d = %s\n", nmas_res, ldap_err2string(nmas_res));
+                        debug("Error reading Universal Password: %d = %s\n", nmas_res, ldap_err2string(nmas_res));
                     }
                 } else {
                     values = ldap_get_values(ld, entry, passattr);
