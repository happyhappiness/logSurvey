                if (strstr(ldapServer, "://") != NULL) {
                    rc = ldap_initialize(&ld, ldapServer);
                    if (rc != LDAP_SUCCESS) {
                        fprintf(stderr, "\nUnable to connect to LDAPURI:%s\n", ldapServer);
                        break;
                    }
                } else
#endif
#if NETSCAPE_SSL
                    if (sslpath) {
                        if (!sslinit && (ldapssl_client_init(sslpath, NULL) != LDAP_SUCCESS)) {
                            fprintf(stderr, "\nUnable to initialise SSL with cert path %s\n",
                                    sslpath);
                            exit(1);
                        } else {
                            sslinit++;
                        }
                        if ((ld = ldapssl_init(ldapServer, port, 1)) == NULL) {
                            fprintf(stderr, "\nUnable to connect to SSL LDAP server: %s port:%d\n",
                                    ldapServer, port);
                            exit(1);
                        }
                    } else
#endif
                        if ((ld = ldap_init(ldapServer, port)) == NULL) {
                            fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n", ldapServer, port);
                            break;
                        }
                if (connect_timeout)
