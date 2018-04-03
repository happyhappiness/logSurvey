                    } else
#endif
                        if ((ld = ldap_init(ldapServer, port)) == NULL) {
                            broken = HLP_MSG("Unable to connect to LDAP server");
                            fprintf(stderr, "ERROR: %s:%s port:%d\n", broken, ldapServer, port);
                            break;
                        }
                if (connect_timeout)
