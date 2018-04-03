 	char *userdn;
 	if (extension_dn && *extension_dn)
 	    snprintf(searchbase, sizeof(searchbase), "%s,%s", extension_dn, userbasedn ? userbasedn : basedn);
+	else
+	    snprintf(searchbase, sizeof(searchbase), "%s", userbasedn ? userbasedn : basedn);
 	ldap_escape_value(escaped_login, sizeof(escaped_login), login);
 	snprintf(filter, sizeof(filter), usersearchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
 	if (debug)
-	    fprintf(stderr, "user filter %s\n", filter);
+	    fprintf(stderr, "user filter '%s', searchbase '%s'\n", filter, searchbase);
 	rc = ldap_search_s(ld, searchbase, searchscope, filter, NULL, 1, &res);
 	if (rc != LDAP_SUCCESS) {
 	    if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
