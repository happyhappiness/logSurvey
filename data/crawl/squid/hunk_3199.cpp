         }
         entry = ldap_first_entry(search_ld, res);
         if (!entry) {
-            if (debug_mode)
-                fprintf(stderr, "Ldap search returned nothing\n");
+            debug("Ldap search returned nothing\n");
             ret = 1;
             goto search_done;
         }
