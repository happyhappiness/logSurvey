                     } else
 #endif
                         if ((ld = ldap_init(ldapServer, port)) == NULL) {
-                            fprintf(stderr, "ERROR: Unable to connect to LDAP server:%s port:%d\n", ldapServer, port);
+                            broken = HLP_MSG("Unable to connect to LDAP server");
+                            fprintf(stderr, "ERROR: %s:%s port:%d\n", broken, ldapServer, port);
                             break;
                         }
                 if (connect_timeout)
