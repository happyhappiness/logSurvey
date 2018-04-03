		/* Everything is fine. This is expected when referrals
		 * are disabled.
		 */
		if (debug)
		    fprintf(stderr, "noreferrals && rc == LDAP_PARTIAL_RESULTS\n");
	    } else {
		fprintf(stderr, PROGRAM_NAME ": WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
