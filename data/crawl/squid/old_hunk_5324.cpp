	}
	entry = ldap_first_entry(ld, res);
	if (!entry) {
	    fprintf(stderr, PROGRAM_NAME " WARNING, User '%s' not found\n", filter);
	    ldap_msgfree(res);
	    return 1;
	}