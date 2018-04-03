		}
		squid_ldap_set_referrals(ld, !noreferrals);
		squid_ldap_set_aliasderef(ld, aliasderef);
		if (binddn && bindpasswd && *binddn && *bindpasswd) {
		    rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
		    if (rc != LDAP_SUCCESS) {
			fprintf(stderr, PROGRAM_NAME " WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
			ldap_unbind(ld);
			ld = NULL;
			break;
		    }
		}
		if (debug)
		    fprintf(stderr, "Connected OK\n");
	    }
	    if (searchLDAP(ld, group, user, extension_dn) == 0) {
		found = 1;
		break;
	    } else {
