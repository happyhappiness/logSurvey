                         fprintf(stderr, "FATAL: TLS requires LDAP version 3\n");
                         exit(1);
                     } else if (ldap_start_tls_s(ld, NULL, NULL) != LDAP_SUCCESS) {
-                        fprintf(stderr, "ERROR: Could not Activate TLS connection\n");
+                        broken = HLP_MSG("Could not Activate TLS connection");
+                        fprintf(stderr, "ERROR: %s\n", broken);
                         ldap_unbind(ld);
                         ld = NULL;
                         break;
