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
