                if (strstr(ldapServer, "://") != NULL) {
                    rc = ldap_initialize(&ld, ldapServer);
                    if (rc != LDAP_SUCCESS) {
                        fprintf(stderr, "%s: ERROR: Unable to connect to LDAPURI:%s\n", argv[0], ldapServer);
                        break;
                    }
