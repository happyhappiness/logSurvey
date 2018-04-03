                    } else
#endif
                        if ((ld = ldap_init(ldapServer, port)) == NULL) {
                            fprintf(stderr, "ERROR: Unable to connect to LDAP server:%s port:%d\n", ldapServer, port);
                            break;
                        }
                if (connect_timeout)
