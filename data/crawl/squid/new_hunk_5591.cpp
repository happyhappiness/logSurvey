static int
searchLDAP(LDAP * ld, char *group, char *member, char *grouprdn)
{
    char filter[256];
    static char searchbase[256];
    LDAPMessage *res = NULL;
    LDAPMessage *entry;

    if (grouprdn)
	snprintf(searchbase, sizeof(searchbase), "%s,%s", grouprdn, basedn);
    else
	snprintf(searchbase, sizeof(searchbase), "%s", basedn);

    ldap_build_filter(filter, sizeof(filter), searchfilter, NULL, NULL, group, member, NULL);
    if (debug)
	printf("filter %s\n", filter);


    if (ldap_search_s(ld, searchbase, searchscope, filter, NULL, 1, &res) != LDAP_SUCCESS) {
	int rc = ldap_result2error(ld, res, 0);
	if (noreferrals && rc == LDAP_PARTIAL_RESULTS) {
	    /* Everything is fine. This is expected when referrals
	     * are disabled.
	     */
	} else {
	    fprintf(stderr, "squid_ldap_match: WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
	}
	ldap_msgfree(res);
	return 1;
    }
    entry = ldap_first_entry(ld, res);
    if (!entry) {
	ldap_msgfree(res);
	return 1;
    }
    ldap_msgfree(res);
    return 0;
}