                            fprintf(stderr, "FATAL: Unable to initialise SSL with cert path %s\n", sslpath);
                            exit(1);
                        } else {
                            sslinit++;
                        }
                        if ((ld = ldapssl_init(ldapServer, port, 1)) == NULL) {
                            fprintf(stderr, "FATAL: Unable to connect to SSL LDAP server: %s port:%d\n",
