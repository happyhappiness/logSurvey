    return 0;
}

static int
ldap_escape_value(char *escaped, int size, const char *src)
{
    int n = 0;
    while (size > 4 && *src) {
        switch (*src) {
        case '*':
        case '(':
        case ')':
        case '\\':
            n += 3;
            size -= 3;
            if (size > 0) {
                *escaped = '\\';
                ++escaped;
                snprintf(escaped, 3, "%02x", (unsigned char) *src);
                ++src;
                escaped += 2;
            }
            break;
        default:
            *escaped = *src;
            ++escaped;
            ++src;
            ++n;
            --size;
        }
    }
    *escaped = '\0';
    return n;
}

static int
build_filter(char *filter, int size, const char *templ, const char *user, const char *group)
{
    int n;
    while (*templ && size > 0) {
        switch (*templ) {
        case '%':
            ++templ;
            switch (*templ) {
            case 'u':
            case 'v':
                ++templ;
                n = ldap_escape_value(filter, size, user);
                size -= n;
                filter += n;
                break;
            case 'g':
            case 'a':
                ++templ;
                n = ldap_escape_value(filter, size, group);
                size -= n;
                filter += n;
                break;
            default:
                fprintf(stderr, "ERROR: Unknown filter template string %%%c\n", *templ);
                return 1;
                break;
            }
            break;
        case '\\':
            ++templ;
            if (*templ) {
                *filter = *templ;
                ++filter;
                ++templ;
                --size;
            }
            break;
        default:
            *filter = *templ;
            ++filter;
            ++templ;
            --size;
            break;
        }
    }
    if (size <= 0) {
        fprintf(stderr, "ERROR: Filter too large\n");
        return 1;
    }
    *filter = '\0';
    return 0;
}

static int
searchLDAPGroup(LDAP * ld, char *group, char *member, char *extension_dn)
{
    char filter[256];
    static char searchbase[256];
    LDAPMessage *res = NULL;
    LDAPMessage *entry;
    int rc;
    char *searchattr[] = {(char *) LDAP_NO_ATTRS, NULL};

    if (extension_dn && *extension_dn)
        snprintf(searchbase, sizeof(searchbase), "%s,%s", extension_dn, basedn);
    else
        snprintf(searchbase, sizeof(searchbase), "%s", basedn);

    if (build_filter(filter, sizeof(filter), searchfilter, member, group) != 0) {
        fprintf(stderr, PROGRAM_NAME ": ERROR: Failed to construct LDAP search filter. filter=\"%s\", user=\"%s\", group=\"%s\"\n", filter, member, group);
        return 1;
    }
    debug("group filter '%s', searchbase '%s'\n", filter, searchbase);

    rc = ldap_search_s(ld, searchbase, searchscope, filter, searchattr, 1, &res);
    if (rc != LDAP_SUCCESS) {
        if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
            /* Everything is fine. This is expected when referrals
             * are disabled.
             */
        } else {
            fprintf(stderr, PROGRAM_NAME ": WARNING: LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
            if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
                int sslerr = PORT_GetError();
                fprintf(stderr, PROGRAM_NAME ": WARNING: SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
            }
#endif
            ldap_msgfree(res);
            return 1;
        }
    }
    entry = ldap_first_entry(ld, res);
    if (!entry) {
        ldap_msgfree(res);
        return 1;
    }
    ldap_msgfree(res);
    return 0;
}

static int
searchLDAP(LDAP * ld, char *group, char *login, char *extension_dn)
{

    if (usersearchfilter) {
        char filter[8192];
        char searchbase[8192];
        char escaped_login[1024];
        LDAPMessage *res = NULL;
        LDAPMessage *entry;
        int rc;
        char *userdn;
        char *searchattr[] = {(char *) LDAP_NO_ATTRS, NULL};
        if (extension_dn && *extension_dn)
            snprintf(searchbase, sizeof(searchbase), "%s,%s", extension_dn, userbasedn ? userbasedn : basedn);
        else
            snprintf(searchbase, sizeof(searchbase), "%s", userbasedn ? userbasedn : basedn);
        ldap_escape_value(escaped_login, sizeof(escaped_login), login);
        snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
        debug("user filter '%s', searchbase '%s'\n", filter, searchbase);
        rc = ldap_search_s(ld, searchbase, searchscope, filter, searchattr, 1, &res);
        if (rc != LDAP_SUCCESS) {
            if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
                /* Everything is fine. This is expected when referrals
                 * are disabled.
                 */
            } else {
                fprintf(stderr, PROGRAM_NAME ": WARNING: LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
                if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
                    int sslerr = PORT_GetError();
                    fprintf(stderr, PROGRAM_NAME ": WARNING: SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
                }
#endif
                ldap_msgfree(res);
                return 1;
            }
        }
        entry = ldap_first_entry(ld, res);
        if (!entry) {
            fprintf(stderr, PROGRAM_NAME ": WARNING: User '%s' not found in '%s'\n", login, searchbase);
            ldap_msgfree(res);
            return 1;
        }
        userdn = ldap_get_dn(ld, entry);
        rc = searchLDAPGroup(ld, group, userdn, extension_dn);
        squid_ldap_memfree(userdn);
        ldap_msgfree(res);
        return rc;
    } else if (userdnattr) {
        char dn[8192];
        if (extension_dn && *extension_dn)
            snprintf(dn, 8192, "%s=%s, %s, %s", userdnattr, login, extension_dn, userbasedn ? userbasedn : basedn);
        else
            snprintf(dn, 8192, "%s=%s, %s", userdnattr, login, userbasedn ? userbasedn : basedn);
        return searchLDAPGroup(ld, group, dn, extension_dn);
    } else {
        return searchLDAPGroup(ld, group, login, extension_dn);
    }