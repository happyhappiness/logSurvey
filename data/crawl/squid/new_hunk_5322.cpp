    }

    if (debug)
	fprintf(stderr, "group filter '%s', searchbase '%s'\n", filter, searchbase);

    rc = ldap_search_s(ld, searchbase, searchscope, filter, NULL, 1, &res);
    if (rc != LDAP_SUCCESS) {
