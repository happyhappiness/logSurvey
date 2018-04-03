	tryagain = 1;
recover:
	if (ld == NULL) {
	    if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
		    ldapServer, LDAP_PORT);
		exit(1);
	    }
	    squid_ldap_set_referrals(ld, !noreferrals);
	    squid_ldap_set_aliasderef(ld, aliasderef);
	}
	rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
	if (rc != LDAP_SUCCESS) {
	    fprintf(stderr, "squid_ldap_match: WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
	    exit(1);
	}
	if (debug) printf("Binding OK\n");
	if (searchLDAP(ld, group, user, grouprdn) != 0) {