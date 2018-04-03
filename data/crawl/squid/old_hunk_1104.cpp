            fprintf(stderr, "ERROR: Your LDAP library does not have URI support\n");
            exit(1);
#endif
            /* Fall thru to -h */
        case 'h':
            if (ldapServer) {
                int len = strlen(ldapServer) + 1 + strlen(value) + 1;
