	    printf("ERR\n");
	    continue;
	}
	tryagain = 1;
      recover:
	if (ld == NULL) {
	    if ((ld = ldap_init(ldapServer, port)) == NULL) {
		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
		    ldapServer, port);
		printf("ERR\n");
		continue;
	    }
	    if (version == -1) {
		version = LDAP_VERSION2;
	    }
	    if (ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version)
		!= LDAP_OPT_SUCCESS) {
		fprintf(stderr, "Could not set LDAP_OPT_PROTOCOL_VERSION %d\n",
		    version);
		ldap_unbind(ld);
		printf("ERR\n");
		continue;
	    }
	    if (use_tls && (version == LDAP_VERSION3) && (ldap_start_tls_s(ld, NULL, NULL) == LDAP_SUCCESS)) {
		fprintf(stderr, "Could not Activate TLS connection\n");
		ldap_unbind(ld);
		printf("ERR\n");
		continue;
	    }
	    squid_ldap_set_referrals(ld, !noreferrals);
	    squid_ldap_set_aliasderef(ld, aliasderef);
	}
