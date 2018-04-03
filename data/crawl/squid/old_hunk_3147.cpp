
        WLDAP32Handle = GetModuleHandle("wldap32");
        if ((Win32_ldap_start_tls_s = (PFldap_start_tls_s) GetProcAddress(WLDAP32Handle, LDAP_START_TLS_S)) == NULL) {
            fprintf(stderr, PROGRAM_NAME ": ERROR: TLS (-Z) not supported on this platform.\n");
            exit(1);
        }
    }
#endif

    while (fgets(buf, 256, stdin) != NULL) {
        int found = 0;
        if (!strchr(buf, '\n')) {
            /* too large message received.. skip and deny */
            fprintf(stderr, "%s: ERROR: Too large: %s\n", argv[0], buf);
            while (fgets(buf, sizeof(buf), stdin)) {
                fprintf(stderr, "%s: ERROR: Too large..: %s\n", argv[0], buf);
                if (strchr(buf, '\n') != NULL)
                    break;
            }
            goto error;
        }
        user = strtok(buf, " \n");
        if (!user) {
            fprintf(stderr, "%s: Invalid request\n", argv[0]);
            goto error;
        }
        rfc1738_unescape(user);
        if (strip_nt_domain) {
