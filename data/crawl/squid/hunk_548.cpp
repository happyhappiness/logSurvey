     return 0;
 }
 
-static int
-ldap_escape_value(char *escaped, int size, const char *src)
+static std::string
+ldap_escape_value(const std::string &src)
 {
-    int n = 0;
-    while (size > 4 && *src) {
-        switch (*src) {
-        case '*':
-        case '(':
-        case ')':
-        case '\\':
-            n += 3;
-            size -= 3;
-            if (size > 0) {
-                *escaped = '\\';
-                ++escaped;
-                snprintf(escaped, 3, "%02x", (unsigned char) *src);
-                ++src;
-                escaped += 2;
-            }
-            break;
-        default:
-            *escaped = *src;
-            ++escaped;
-            ++src;
-            ++n;
-            --size;
+    std::stringstream str;
+    for (const auto &c : src) {
+        switch (c) {
+            case '*':
+            case '(':
+            case ')':
+            case '\\':
+                str << '\\' << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(c);
+                break;
+            default:
+                str << c;
         }
     }
-    *escaped = '\0';
-    return n;
+    return str.str();
 }
 
-static int
-build_filter(char *filter, int size, const char *templ, const char *user, const char *group)
+static bool
+build_filter(std::string &filter, const char *templ, const char *user, const char *group)
 {
-    int n;
-    while (*templ && size > 0) {
+    std::stringstream str;
+    while (*templ) {
         switch (*templ) {
         case '%':
             ++templ;
             switch (*templ) {
             case 'u':
             case 'v':
                 ++templ;
-                n = ldap_escape_value(filter, size, user);
-                size -= n;
-                filter += n;
+                str << ldap_escape_value(user);
                 break;
             case 'g':
             case 'a':
                 ++templ;
-                n = ldap_escape_value(filter, size, group);
-                size -= n;
-                filter += n;
+                str << ldap_escape_value(group);
                 break;
             default:
                 fprintf(stderr, "ERROR: Unknown filter template string %%%c\n", *templ);
-                return 1;
-                break;
+                filter = str.str();
+                return false;
             }
             break;
         case '\\':
             ++templ;
             if (*templ) {
-                *filter = *templ;
-                ++filter;
+                str << *templ;
                 ++templ;
-                --size;
             }
             break;
         default:
-            *filter = *templ;
-            ++filter;
+            str << *templ;
             ++templ;
-            --size;
             break;
         }
     }
-    if (size <= 0) {
-        fprintf(stderr, "ERROR: Filter too large\n");
-        return 1;
+    filter = str.str();
+    return true;
+}
+
+static std::string
+build_searchbase(const char *extension_dn, const char *base_dn)
+{
+    std::stringstream searchBaseStream;
+    if (extension_dn && *extension_dn)
+        searchBaseStream << extension_dn << ",";
+    searchBaseStream << basedn;
+    return searchBaseStream.str();
+}
+
+static bool ldap_search_ok(const int result)
+{
+    if (result == LDAP_SUCCESS)
+        return true;
+    if (noreferrals && result == LDAP_PARTIAL_RESULTS) {
+            /* Everything is fine. This is expected when referrals
+             * are disabled.
+             */
+        return true;
     }
-    *filter = '\0';
-    return 0;
+    std::cerr << PROGRAM_NAME << ": WARNING: LDAP search error '" <<
+        ldap_err2string(result) << "'" << std::endl;
+#if defined(NETSCAPE_SSL)
+    if (sslpath && ((result == LDAP_SERVER_DOWN) || (result == LDAP_CONNECT_ERROR))) {
+        int sslerr = PORT_GetError();
+        std::cerr << PROGRAM_NAME << ": WARNING: SSL error " << sslerr << " (" <<
+            ldapssl_err2string(sslerr) << ")" << std::endl;
+    }
+#endif
+    return false;
 }
 
+typedef const std::unique_ptr<LDAPMessage, decltype(&ldap_msgfree)> LdapResult;
+
 static int
-searchLDAPGroup(LDAP * ld, char *group, char *member, char *extension_dn)
+searchLDAPGroup(LDAP * ld, const char *group, const char *member, const char *extension_dn)
 {
-    char filter[256];
-    static char searchbase[256];
+    std::string filter;
     LDAPMessage *res = NULL;
-    LDAPMessage *entry;
     int rc;
     char *searchattr[] = {(char *) LDAP_NO_ATTRS, NULL};
 
-    if (extension_dn && *extension_dn)
-        snprintf(searchbase, sizeof(searchbase), "%s,%s", extension_dn, basedn);
-    else
-        snprintf(searchbase, sizeof(searchbase), "%s", basedn);
-
-    if (build_filter(filter, sizeof(filter), searchfilter, member, group) != 0) {
-        fprintf(stderr, PROGRAM_NAME ": ERROR: Failed to construct LDAP search filter. filter=\"%s\", user=\"%s\", group=\"%s\"\n", filter, member, group);
+    const std::string searchbase = build_searchbase(extension_dn, basedn);
+    if (!build_filter(filter, searchfilter, member, group)) {
+        std::cerr << PROGRAM_NAME  << ": ERROR: Failed to construct LDAP search filter. filter=\"" <<
+            filter.c_str() << "\", user=\"" << member << "\", group=\"" << group << "\"" << std::endl;
         return 1;
     }
-    debug("group filter '%s', searchbase '%s'\n", filter, searchbase);
+    debug("group filter '%s', searchbase '%s'\n", filter.c_str(), searchbase.c_str());
 
-    rc = ldap_search_s(ld, searchbase, searchscope, filter, searchattr, 1, &res);
-    if (rc != LDAP_SUCCESS) {
-        if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
-            /* Everything is fine. This is expected when referrals
-             * are disabled.
-             */
-        } else {
-            fprintf(stderr, PROGRAM_NAME ": WARNING: LDAP search error '%s'\n", ldap_err2string(rc));
-#if defined(NETSCAPE_SSL)
-            if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
-                int sslerr = PORT_GetError();
-                fprintf(stderr, PROGRAM_NAME ": WARNING: SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
-            }
-#endif
-            ldap_msgfree(res);
-            return 1;
-        }
-    }
-    entry = ldap_first_entry(ld, res);
-    if (!entry) {
-        ldap_msgfree(res);
+    rc = ldap_search_s(ld, searchbase.c_str(), searchscope, filter.c_str(), searchattr, 1, &res);
+    LdapResult ldapRes(res, ldap_msgfree);
+    if (!ldap_search_ok(rc))
         return 1;
+
+    return ldap_first_entry(ld, ldapRes.get()) ? 0 : 1;
+}
+
+static void
+formatWithString(std::string &formatted, const std::string &value)
+{
+    size_t start_pos = 0;
+    while ((start_pos = formatted.find("%s", start_pos)) != std::string::npos) {
+        formatted.replace(start_pos, 2, value);
+        start_pos += 2;
     }
-    ldap_msgfree(res);
-    return 0;
 }
 
 static int
 searchLDAP(LDAP * ld, char *group, char *login, char *extension_dn)
 {
 
+    const char *current_userdn = userbasedn ? userbasedn : basedn;
     if (usersearchfilter) {
-        char filter[8192];
-        char searchbase[8192];
-        char escaped_login[1024];
         LDAPMessage *res = NULL;
         LDAPMessage *entry;
         int rc;
         char *userdn;
         char *searchattr[] = {(char *) LDAP_NO_ATTRS, NULL};
-        if (extension_dn && *extension_dn)
-            snprintf(searchbase, sizeof(searchbase), "%s,%s", extension_dn, userbasedn ? userbasedn : basedn);
-        else
-            snprintf(searchbase, sizeof(searchbase), "%s", userbasedn ? userbasedn : basedn);
-        ldap_escape_value(escaped_login, sizeof(escaped_login), login);
-        snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
-        debug("user filter '%s', searchbase '%s'\n", filter, searchbase);
-        rc = ldap_search_s(ld, searchbase, searchscope, filter, searchattr, 1, &res);
-        if (rc != LDAP_SUCCESS) {
-            if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
-                /* Everything is fine. This is expected when referrals
-                 * are disabled.
-                 */
-            } else {
-                fprintf(stderr, PROGRAM_NAME ": WARNING: LDAP search error '%s'\n", ldap_err2string(rc));
-#if defined(NETSCAPE_SSL)
-                if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
-                    int sslerr = PORT_GetError();
-                    fprintf(stderr, PROGRAM_NAME ": WARNING: SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
-                }
-#endif
-                ldap_msgfree(res);
-                return 1;
-            }
-        }
-        entry = ldap_first_entry(ld, res);
+        const std::string searchbase = build_searchbase(extension_dn, current_userdn);
+        std::string filter(usersearchfilter);
+        const std::string escaped_login = ldap_escape_value(login);
+        formatWithString(filter, escaped_login);
+
+        debug("user filter '%s', searchbase '%s'\n", filter.c_str(), searchbase.c_str());
+        rc = ldap_search_s(ld, searchbase.c_str(), searchscope, filter.c_str(), searchattr, 1, &res);
+        LdapResult ldapRes(res, ldap_msgfree);
+        if (!ldap_search_ok(rc))
+            return 1;
+        entry = ldap_first_entry(ld, ldapRes.get());
         if (!entry) {
-            fprintf(stderr, PROGRAM_NAME ": WARNING: User '%s' not found in '%s'\n", login, searchbase);
-            ldap_msgfree(res);
+            std::cerr << PROGRAM_NAME << ": WARNING: User '" << login <<
+                " not found in '" << searchbase.c_str() << "'" << std::endl;
             return 1;
         }
         userdn = ldap_get_dn(ld, entry);
         rc = searchLDAPGroup(ld, group, userdn, extension_dn);
         squid_ldap_memfree(userdn);
-        ldap_msgfree(res);
         return rc;
     } else if (userdnattr) {
-        char dn[8192];
+        std::stringstream str;
+        str << userdnattr << "=" << login << ", ";
         if (extension_dn && *extension_dn)
-            snprintf(dn, 8192, "%s=%s, %s, %s", userdnattr, login, extension_dn, userbasedn ? userbasedn : basedn);
-        else
-            snprintf(dn, 8192, "%s=%s, %s", userdnattr, login, userbasedn ? userbasedn : basedn);
-        return searchLDAPGroup(ld, group, dn, extension_dn);
+            str << extension_dn << ", ";
+        str << current_userdn;
+        return searchLDAPGroup(ld, group, str.str().c_str(), extension_dn);
     } else {
         return searchLDAPGroup(ld, group, login, extension_dn);
     }