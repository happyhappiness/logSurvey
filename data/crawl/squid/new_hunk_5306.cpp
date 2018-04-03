	}
	userdn = ldap_get_dn(ld, entry);
	if (!userdn) {
	    fprintf(stderr, PROGRAM_NAME ": ERROR, could not get user DN for '%s'\n", userid);
	    ldap_msgfree(res);
	    return 1;
	}
