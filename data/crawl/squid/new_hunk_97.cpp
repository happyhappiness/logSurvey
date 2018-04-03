                    version = LDAP_VERSION3;
                }
                if (ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version) != LDAP_SUCCESS) {
                    broken = HLP_MSG("Could not set LDAP_OPT_PROTOCOL_VERSION");
                    fprintf(stderr, "ERROR: %s %d\n", broken, version);
                    ldap_unbind(ld);
                    ld = NULL;
                    break;
