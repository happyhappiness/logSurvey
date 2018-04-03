            }
        }
        snprintf(filter, sizeof(filter), searchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
        if (debug_mode)
            fprintf(stderr, "user filter '%s', searchbase '%s'\n", filter, basedn);
        rc = ldap_search_s(search_ld, basedn, searchscope, filter, searchattr, 1, &res);
        if (rc != LDAP_SUCCESS) {
            if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
                /* Everything is fine. This is expected when referrals
                 * are disabled.
                 */
                if (debug_mode)
                    fprintf(stderr, "noreferrals && rc == LDAP_PARTIAL_RESULTS\n");
            } else {
                fprintf(stderr, PROGRAM_NAME ": WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
