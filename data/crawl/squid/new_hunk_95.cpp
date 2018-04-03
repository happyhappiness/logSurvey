                if (strstr(ldapServer, "://") != NULL) {
                    rc = ldap_initialize(&ld, ldapServer);
                    if (rc != LDAP_SUCCESS) {
                        broken = HLP_MSG("Unable to connect to LDAP server");
                        fprintf(stderr, "%s: ERROR: Unable to connect to LDAPURI:%s\n", argv[0], ldapServer);
                        break;
                    }
