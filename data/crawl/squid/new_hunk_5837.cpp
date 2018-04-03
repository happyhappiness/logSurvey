	LDAPMessage *entry;
	char *searchattr[] = {NULL};
	char *userdn;
	int rc;

	if (binddn) {
	    rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
	    if (rc != LDAP_SUCCESS) {
		fprintf(stderr, "squid_ldap_auth: WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
		return 1;
	    }
	}
	snprintf(filter, sizeof(filter), "%s%s", searchfilter, userid);
	if (ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res) != LDAP_SUCCESS) {
	    int rc = ldap_result2error(ld, res, 0);
	    if (rc != LDAP_PARTIAL_RESULTS) {
		/* LDAP_PARTIAL_RESULT ignored. What we are looking for
		 * is most likely availale
		 * This error is seen when querying a MS ActiveDirector
		 * server due to referrals..
		 */
		fprintf(stderr, "squid_ldap_auth: WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
	    }
	}
	entry = ldap_first_entry(ld, res);
	if (!entry) {
	    ldap_msgfree(res);