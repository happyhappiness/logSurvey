    int nmas_res = 0;
    int rc = -1;
    if (ld) {
        if (usersearchfilter) {
            char escaped_login[1024];
            snprintf(searchbase, sizeof(searchbase), "%s", userbasedn);
            ldap_escape_value(escaped_login, sizeof(escaped_login), login);
            snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);

retrysrch:
            if (debug)
                fprintf(stderr, "user filter '%s', searchbase '%s'\n", filter, searchbase);

            rc = ldap_search_s(ld, searchbase, searchscope, filter, NULL, 0, &res);
            if (rc != LDAP_SUCCESS) {
                if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
                    /* Everything is fine. This is expected when referrals
                     * are disabled.
                     */
                    rc = LDAP_SUCCESS;
                } else {
                    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
                    if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
                        int sslerr = PORT_GetError();
                        fprintf(stderr, PROGRAM_NAME ": WARNING, SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
                    }
#endif
                    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error, trying to recover'%s'\n", ldap_err2string(rc));
                    ldap_msgfree(res);
                    /* try to connect to the LDAP server agin, maybe my persisten conexion failed. */
                    if (!retry) {
                        retry++;
                        ldap_unbind(ld);
                        ld = NULL;
                        ldapconnect();
                        goto retrysrch;
                    }
                    return NULL;

                }
            }
        } else if (userdnattr) {
            sprintf(searchbase, "%s=%s, %s", userdnattr, login, userbasedn);

retrydnattr:
            if (debug)
                fprintf(stderr, "searchbase '%s'\n", searchbase);
            rc = ldap_search_s(ld, searchbase, searchscope, NULL, NULL, 0, &res);
        }
        if (rc == LDAP_SUCCESS) {
            entry = ldap_first_entry(ld, res);
            if (entry) {
                if (debug)
                    printf("ldap dn: %s\n", ldap_get_dn(ld, entry));
                if (edir_universal_passwd) {

                    /* allocate some memory for the universal password returned by NMAS */
                    universal_password = malloc(universal_password_len);
                    memset(universal_password, 0, universal_password_len);
                    values = malloc(sizeof(char *));

                    /* actually talk to NMAS to get a password */
                    nmas_res = nds_get_password(ld, ldap_get_dn(ld, entry), &universal_password_len, universal_password);
                    if (nmas_res == LDAP_SUCCESS && universal_password) {
                        if (debug)
                            printf("NMAS returned value %s\n", universal_password);
                        values[0] = universal_password;
                    } else {
                        if (debug)
                            printf("Error reading Universal Password: %d = %s\n", nmas_res, ldap_err2string(nmas_res));
                    }
                } else {
                    values = ldap_get_values(ld, entry, passattr);
                }
            } else {
                ldap_msgfree(res);
                return NULL;
            }
            if (!values) {
                if (debug)
                    printf("No attribute value found\n");
                if (edir_universal_passwd)
                    free(universal_password);
                ldap_msgfree(res);
                return NULL;
            }
            value = values;
            while (*value) {
                if (encrpass) {
                    if (strcmp(strtok(*value, delimiter), realm) == 0) {
                        password = strtok(NULL, delimiter);
                        break;
                    }
                } else {
                    password = *value;
                    break;
                }
                value++;
            }
            if (debug)
                printf("password: %s\n", password);
            if (password)
                password = strdup(password);
            if (edir_universal_passwd) {
                free(values);
                free(universal_password);
            } else {
                ldap_value_free(values);
            }
            ldap_msgfree(res);
            return password;
        } else {
            fprintf(stderr, PROGRAM_NAME " WARNING, LDAP error '%s'\n", ldap_err2string(rc));
            /* try to connect to the LDAP server agin, maybe my persisten conexion failed. */
            if (!retry) {
                retry++;
                ldap_unbind(ld);
                ld = NULL;
                ldapconnect();
                goto retrydnattr;
            }
            return NULL;
        }
    }
    return NULL;
}
