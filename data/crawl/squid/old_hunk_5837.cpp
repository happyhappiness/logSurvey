	LDAPMessage *entry;
	char *searchattr[] = {NULL};
	char *userdn;

	if (binddn) {
	    if (ldap_simple_bind_s(ld, binddn, bindpasswd) != LDAP_SUCCESS) {
		fprintf(stderr, "squid_ldap_auth: WARNING, could not bind to binddn '%s'\n", binddn);
		return 1;
	    }
	}
	snprintf(filter, sizeof(filter), "%s%s", searchfilter, userid);
	if (ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res) != LDAP_SUCCESS)
	    return 1;
	entry = ldap_first_entry(ld, res);
	if (!entry) {
	    ldap_msgfree(res);