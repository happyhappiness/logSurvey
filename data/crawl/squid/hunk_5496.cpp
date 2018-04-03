     ldap_msgfree(res);
     return 0;
 }
+
+static int
+searchLDAP(LDAP *ld, char *group, char *login, char *extension_dn)
+{
+
+    if (usersearchfilter) {
+	char filter[8192];
+	char searchbase[8192];
+	char escaped_login[1024];
+	LDAPMessage *res = NULL;
+	LDAPMessage *entry;
+	int rc;
+	char *userdn;
+	ldap_escape_value(escaped_login, sizeof(escaped_login), login);
+	snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
+	if (debug)
+	    fprintf(stderr, "user filter %s\n", filter);
+	rc = ldap_search_s(ld, userbasedn ? userbasedn : basedn, searchscope, filter, NULL, 1, &res);
+	if (rc != LDAP_SUCCESS) {
+	    if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
+		/* Everything is fine. This is expected when referrals
+		 * are disabled.
+		 */
+	    } else {
+		fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
+		ldap_msgfree(res);
+		return 1;
+	    }
+	}
+	entry = ldap_first_entry(ld, res);
+	if (!entry) {
+	    fprintf(stderr, PROGRAM_NAME " WARNING, User '%s' not found\n", filter);
+	    ldap_msgfree(res);
+	    return 1;
+	}
+	userdn = ldap_get_dn(ld, entry);
+	rc = searchLDAPGroup(ld, group, userdn, extension_dn);
+	squid_ldap_memfree(userdn);
+	ldap_msgfree(res);
+	return rc;
+    } else if (userdnattr) {
+	char dn[8192];
+	if (extension_dn && *extension_dn)
+	    sprintf(dn, "%s=%s, %s, %s", userdnattr, login, extension_dn, userbasedn ? userbasedn : basedn);
+	else
+	    sprintf(dn, "%s=%s, %s", userdnattr, login, userbasedn ? userbasedn : basedn);
+	return searchLDAPGroup(ld, group, dn, extension_dn);
+    } else {
+	return searchLDAPGroup(ld, group, login, extension_dn);
+    }
+}