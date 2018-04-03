	     */
	} else {
	    fprintf(stderr, PROGRAM_NAME " WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
	    ldap_msgfree(res);
	    return 1;
	}
