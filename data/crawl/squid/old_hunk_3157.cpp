            snprintf(searchbase, sizeof(searchbase), "%s", userbasedn ? userbasedn : basedn);
        ldap_escape_value(escaped_login, sizeof(escaped_login), login);
        snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
        if (show_debug_messages)
            fprintf(stderr, "user filter '%s', searchbase '%s'\n", filter, searchbase);
        rc = ldap_search_s(ld, searchbase, searchscope, filter, searchattr, 1, &res);
        if (rc != LDAP_SUCCESS) {
            if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
                /* Everything is fine. This is expected when referrals
                 * are disabled.
                 */
            } else {
                fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
                if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
                    int sslerr = PORT_GetError();
                    fprintf(stderr, PROGRAM_NAME ": WARNING, SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
                }
#endif
                ldap_msgfree(res);
