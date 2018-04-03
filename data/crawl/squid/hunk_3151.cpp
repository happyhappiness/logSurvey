                 if (use_tls) {
 #ifdef LDAP_OPT_X_TLS
                     if (version != LDAP_VERSION3) {
-                        fprintf(stderr, "TLS requires LDAP version 3\n");
+                        fprintf(stderr, "FATAL: TLS requires LDAP version 3\n");
                         exit(1);
                     } else if (ldap_start_tls_s(ld, NULL, NULL) != LDAP_SUCCESS) {
-                        fprintf(stderr, "Could not Activate TLS connection\n");
+                        fprintf(stderr, "ERROR: Could not Activate TLS connection\n");
                         ldap_unbind(ld);
                         ld = NULL;
                         break;
                     }
 #else
-                    fprintf(stderr, "TLS not supported with your LDAP library\n");
+                    fprintf(stderr, "FATAL: TLS not supported with your LDAP library\n");
                     exit(1);
 #endif
                 }
