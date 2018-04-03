                        fprintf(stderr, "FATAL: TLS requires LDAP version 3\n");
                        exit(1);
                    } else if (ldap_start_tls_s(ld, NULL, NULL) != LDAP_SUCCESS) {
                        fprintf(stderr, "ERROR: Could not Activate TLS connection\n");
                        ldap_unbind(ld);
                        ld = NULL;
                        break;
