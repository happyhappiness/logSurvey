		 * are disabled.
		 */
	    } else {
		fprintf(stderr, "squid_ldap_auth: WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
	    }
	}
	entry = ldap_first_entry(ld, res);
