
        WLDAP32Handle = GetModuleHandle("wldap32");
        if ((Win32_ldap_start_tls_s = (PFldap_start_tls_s) GetProcAddress(WLDAP32Handle, LDAP_START_TLS_S)) == NULL) {
            fprintf(stderr, PROGRAM_NAME ": FATAL: TLS (-Z) not supported on this platform.\n");
            exit(1);
        }
    }
#endif

    while (fgets(buf, HELPER_INPUT_BUFFER, stdin) != NULL) {
        int found = 0;
        if (!strchr(buf, '\n')) {
            /* too large message received.. skip and deny */
            fprintf(stderr, "%s: ERROR: Input Too large: %s\n", argv[0], buf);
            while (fgets(buf, sizeof(buf), stdin)) {
                fprintf(stderr, "%s: ERROR: Input Too large..: %s\n", argv[0], buf);
                if (strchr(buf, '\n') != NULL)
                    break;
            }
            SEND_ERR("");
            continue;
        }
        user = strtok(buf, " \n");
        if (!user) {
            debug("%s: Invalid request: No Username given\n", argv[0]);
            SEND_ERR("Invalid request. No Username");
            continue;
        }
        rfc1738_unescape(user);
        if (strip_nt_domain) {
