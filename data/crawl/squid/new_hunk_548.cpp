    return 0;
}

static std::string
ldap_escape_value(const std::string &src)
{
    std::stringstream str;
    for (const auto &c : src) {
        switch (c) {
            case '*':
            case '(':
            case ')':
            case '\\':
                str << '\\' << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(c);
                break;
            default:
                str << c;
        }
    }
    return str.str();
}

static bool
build_filter(std::string &filter, const char *templ, const char *user, const char *group)
{
    std::stringstream str;
    while (*templ) {
        switch (*templ) {
        case '%':
            ++templ;
            switch (*templ) {
            case 'u':
            case 'v':
                ++templ;
                str << ldap_escape_value(user);
                break;
            case 'g':
            case 'a':
                ++templ;
                str << ldap_escape_value(group);
                break;
            default:
                fprintf(stderr, "ERROR: Unknown filter template string %%%c\n", *templ);
                filter = str.str();
                return false;
            }
            break;
        case '\\':
            ++templ;
            if (*templ) {
                str << *templ;
                ++templ;
            }
            break;
        default:
            str << *templ;
            ++templ;
            break;
        }
    }
    filter = str.str();
    return true;
}

static std::string
build_searchbase(const char *extension_dn, const char *base_dn)
{
    std::stringstream searchBaseStream;
    if (extension_dn && *extension_dn)
        searchBaseStream << extension_dn << ",";
    searchBaseStream << basedn;
    return searchBaseStream.str();
}

static bool ldap_search_ok(const int result)
{
    if (result == LDAP_SUCCESS)
        return true;
    if (noreferrals && result == LDAP_PARTIAL_RESULTS) {
            /* Everything is fine. This is expected when referrals
             * are disabled.
             */
        return true;
    }
    std::cerr << PROGRAM_NAME << ": WARNING: LDAP search error '" <<
        ldap_err2string(result) << "'" << std::endl;
#if defined(NETSCAPE_SSL)
    if (sslpath && ((result == LDAP_SERVER_DOWN) || (result == LDAP_CONNECT_ERROR))) {
        int sslerr = PORT_GetError();
        std::cerr << PROGRAM_NAME << ": WARNING: SSL error " << sslerr << " (" <<
            ldapssl_err2string(sslerr) << ")" << std::endl;
    }
#endif
    return false;
}

typedef const std::unique_ptr<LDAPMessage, decltype(&ldap_msgfree)> LdapResult;

static int
searchLDAPGroup(LDAP * ld, const char *group, const char *member, const char *extension_dn)
{
    std::string filter;
    LDAPMessage *res = NULL;
    int rc;
    char *searchattr[] = {(char *) LDAP_NO_ATTRS, NULL};

    const std::string searchbase = build_searchbase(extension_dn, basedn);
    if (!build_filter(filter, searchfilter, member, group)) {
        std::cerr << PROGRAM_NAME  << ": ERROR: Failed to construct LDAP search filter. filter=\"" <<
            filter.c_str() << "\", user=\"" << member << "\", group=\"" << group << "\"" << std::endl;
        return 1;
    }
    debug("group filter '%s', searchbase '%s'\n", filter.c_str(), searchbase.c_str());

    rc = ldap_search_s(ld, searchbase.c_str(), searchscope, filter.c_str(), searchattr, 1, &res);
    LdapResult ldapRes(res, ldap_msgfree);
    if (!ldap_search_ok(rc))
        return 1;

    return ldap_first_entry(ld, ldapRes.get()) ? 0 : 1;
}

static void
formatWithString(std::string &formatted, const std::string &value)
{
    size_t start_pos = 0;
    while ((start_pos = formatted.find("%s", start_pos)) != std::string::npos) {
        formatted.replace(start_pos, 2, value);
        start_pos += 2;
    }
}

static int
searchLDAP(LDAP * ld, char *group, char *login, char *extension_dn)
{

    const char *current_userdn = userbasedn ? userbasedn : basedn;
    if (usersearchfilter) {
        LDAPMessage *res = NULL;
        LDAPMessage *entry;
        int rc;
        char *userdn;
        char *searchattr[] = {(char *) LDAP_NO_ATTRS, NULL};
        const std::string searchbase = build_searchbase(extension_dn, current_userdn);
        std::string filter(usersearchfilter);
        const std::string escaped_login = ldap_escape_value(login);
        formatWithString(filter, escaped_login);

        debug("user filter '%s', searchbase '%s'\n", filter.c_str(), searchbase.c_str());
        rc = ldap_search_s(ld, searchbase.c_str(), searchscope, filter.c_str(), searchattr, 1, &res);
        LdapResult ldapRes(res, ldap_msgfree);
        if (!ldap_search_ok(rc))
            return 1;
        entry = ldap_first_entry(ld, ldapRes.get());
        if (!entry) {
            std::cerr << PROGRAM_NAME << ": WARNING: User '" << login <<
                " not found in '" << searchbase.c_str() << "'" << std::endl;
            return 1;
        }
        userdn = ldap_get_dn(ld, entry);
        rc = searchLDAPGroup(ld, group, userdn, extension_dn);
        squid_ldap_memfree(userdn);
        return rc;
    } else if (userdnattr) {
        std::stringstream str;
        str << userdnattr << "=" << login << ", ";
        if (extension_dn && *extension_dn)
            str << extension_dn << ", ";
        str << current_userdn;
        return searchLDAPGroup(ld, group, str.str().c_str(), extension_dn);
    } else {
        return searchLDAPGroup(ld, group, login, extension_dn);
    }