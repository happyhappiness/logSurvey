    }
    if (searchfilter) {
	char filter[256];
	LDAPMessage *res = NULL;
	LDAPMessage *entry;
	char *searchattr[] =
	{NULL};
	char *userdn;
	int rc;

	if (binddn) {
	    rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
	    if (rc != LDAP_SUCCESS) {
		fprintf(stderr, PROGRAM_NAME ": WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
		return 1;
	    }
	}
	snprintf(filter, sizeof(filter), searchfilter, userid, userid, userid, userid, userid, userid, userid, userid, userid, userid, userid, userid, userid, userid, userid);
	rc = ldap_search_s(ld, basedn, searchscope, filter, searchattr, 1, &res);
	if (rc != LDAP_SUCCESS) {
	    if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
