	{NULL};
	char *userdn;
	int rc;

	ldap_escape_value(escaped_login, sizeof(escaped_login), userid);
	if (binddn) {
	    rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
	    if (rc != LDAP_SUCCESS) {
		fprintf(stderr, PROGRAM_NAME ": WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
		return 1;
	    }
	}
	snprintf(filter, sizeof(filter), searchfilter, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login, escaped_login);
	if (debug)
	    fprintf(stderr, "user filter '%s', searchbase '%s'\n", filter, basedn);
	rc = ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res);
	if (rc != LDAP_SUCCESS) {
	    if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
		/* Everything is fine. This is expected when referrals
