		/* Everything is fine. This is expected when referrals
		 * are disabled.
		 */
	    } else {
		fprintf(stderr, PROGRAM_NAME ": WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
#if defined(NETSCAPE_SSL)
