	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
	fprintf(stderr, "\t-v 1|2\t\t\tLDAP version\n");
	fprintf(stderr, "\t-Z\t\t\tTLS encrypt the LDAP connection, requires LDAP version 3\n");
	fprintf(stderr, "\t-g\t\t\tfirst query parameter is additional groups base RDN for this query\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
	exit(1);
    }
    while (fgets(buf, 256, stdin) != NULL) {
	char *t;
	int found = 0;
	user = strwordtok(buf, &t);
	if (use_grouprdn)
		grouprdn = strwordtok(NULL, &t);

	tryagain = 1;
	while (!found && user && (group = strwordtok(NULL, &t)) != NULL) {

	  recover:
	    if (ld == NULL) {
		if ((ld = ldap_init(ldapServer, port)) == NULL) {
		    fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
			ldapServer, port);
		    break;
		}
		if (version == -1) {
		    version = LDAP_VERSION2;
		}
		if (ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version)
		    != LDAP_OPT_SUCCESS) {
		    fprintf(stderr, "Could not set LDAP_OPT_PROTOCOL_VERSION %d\n",
			version);
		    ldap_unbind(ld);
		    ld = NULL;
		    break;
		}
		if (use_tls && (version == LDAP_VERSION3) && (ldap_start_tls_s(ld, NULL, NULL) == LDAP_SUCCESS)) {
		    fprintf(stderr, "Could not Activate TLS connection\n");
		    ldap_unbind(ld);
		    ld = NULL;
		    break;
		}
		squid_ldap_set_referrals(ld, !noreferrals);
		squid_ldap_set_aliasderef(ld, aliasderef);
	    }
	    rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
	    if (rc != LDAP_SUCCESS) {
		fprintf(stderr, "squid_ldap_match: WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
		ldap_unbind(ld);
		ld = NULL;
		break;
	    }
	    if (debug)
		printf("Binding OK\n");
	    if (searchLDAP(ld, group, user, grouprdn) == 0) {
		found = 1;
		break;
	    } else {
		if (tryagain) {
		    tryagain = 0;
		    ldap_unbind(ld);
		    ld = NULL;
		    goto recover;
		}
	    }
	}
	if (found)
	    printf("OK\n");
	else
	    printf("ERR\n");

	if (ld != NULL) {
	    if (!persistent || (squid_ldap_errno(ld) != LDAP_SUCCESS && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS)) {
		ldap_unbind(ld);
		ld = NULL;
	    }
	}
    }
    if (ld)